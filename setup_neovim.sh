#!/usr/bin/env bash
set -euo pipefail

echo "======================================================"
echo "  Neovim IDE Setup Script (lazy.nvim + LSP + Treesitter)"
echo "======================================================"

# -----------------------------------------------------------------------
# 0. Back up any existing Neovim config/data (safety net, never overwrite)
# -----------------------------------------------------------------------
TIMESTAMP=$(date +%Y%m%d_%H%M%S)
for dir in "$HOME/.config/nvim" "$HOME/.local/share/nvim" "$HOME/.local/state/nvim" "$HOME/.cache/nvim"; do
  if [ -d "$dir" ]; then
    echo "==> Backing up existing $dir -> ${dir}.bak_${TIMESTAMP}"
    mv "$dir" "${dir}.bak_${TIMESTAMP}"
  fi
done

# -----------------------------------------------------------------------
# 1. Prerequisite packages
# -----------------------------------------------------------------------
echo "==> Installing prerequisite packages..."
sudo apt update
sudo apt install -y \
  git curl build-essential unzip \
  ripgrep fd-find \
  nodejs npm \
  python3 python3-pip python3-venv \
  xclip software-properties-common

# fd-find installs its binary as 'fdfind' on Debian/Ubuntu - symlink to 'fd'
mkdir -p "$HOME/.local/bin"
if ! command -v fd >/dev/null 2>&1; then
  ln -sf "$(command -v fdfind)" "$HOME/.local/bin/fd"
fi
case ":${PATH}:" in
  *":$HOME/.local/bin:"*) ;;
  *) echo 'export PATH="$HOME/.local/bin:$PATH"' >> "$HOME/.bashrc" ;;
esac
export PATH="$HOME/.local/bin:$PATH"

# -----------------------------------------------------------------------
# 2. Neovim itself (Ubuntu's apt repo build is usually too old for modern
#    plugins, so we pull the latest stable release from the official PPA)
# -----------------------------------------------------------------------
echo "==> Removing any conflicting pre-existing Neovim installs..."
# A snap install of nvim takes priority in PATH over /usr/bin/nvim from apt,
# and silently leaves you on an old version even after the PPA install below.
if command -v snap >/dev/null 2>&1 && snap list 2>/dev/null | grep -q '^nvim '; then
  echo "    Found nvim installed via snap - removing it."
  sudo snap remove nvim
fi
# Also drop any apt-installed nvim so the PPA version below is a clean reinstall,
# not a no-op because a same-or-newer-looking version is already "installed".
if dpkg -l neovim 2>/dev/null | grep -q '^ii'; then
  echo "    Found nvim installed via apt - purging before reinstalling from PPA."
  sudo apt purge -y neovim
fi

echo "==> Installing latest stable Neovim from PPA..."
sudo add-apt-repository -y ppa:neovim-ppa/stable
sudo apt update
sudo apt install -y neovim

echo "==> Verifying Neovim version..."
nvim --version | head -n 1
echo "    nvim resolves to: $(command -v nvim)"

NVIM_MAJOR=$(nvim --version | head -n1 | grep -oP '(?<=v)\d+' | head -n1)
NVIM_MINOR=$(nvim --version | head -n1 | grep -oP '(?<=v\d\.)\d+' | head -n1)
if [ "${NVIM_MAJOR:-0}" -eq 0 ] && [ "${NVIM_MINOR:-0}" -lt 10 ]; then
  echo ""
  echo "ERROR: Neovim is still version 0.${NVIM_MINOR}, but the plugins below"
  echo "require 0.10+. Something on this machine (a flatpak install, a manual"
  echo "binary in ~/.local/bin, /usr/local/bin, etc.) is likely shadowing the"
  echo "PPA build in PATH. Check with: which -a nvim"
  echo "Aborting before installing plugins to avoid the same crash loop."
  exit 1
fi

# -----------------------------------------------------------------------
# 3. Config folder structure
# -----------------------------------------------------------------------
NVIM_CONFIG="$HOME/.config/nvim"
echo "==> Creating config directories at $NVIM_CONFIG ..."
mkdir -p "$NVIM_CONFIG/lua/core"
mkdir -p "$NVIM_CONFIG/lua/plugins"

# -----------------------------------------------------------------------
# 4. init.lua
# -----------------------------------------------------------------------
cat << 'EOF' > "$NVIM_CONFIG/init.lua"
-- Leader key must be set before lazy.nvim loads any plugins
vim.g.mapleader = " "
vim.g.maplocalleader = " "

require("core.options")
require("core.keymaps")
require("core.lazy")
EOF

# -----------------------------------------------------------------------
# 5. core/options.lua
# -----------------------------------------------------------------------
cat << 'EOF' > "$NVIM_CONFIG/lua/core/options.lua"
local opt = vim.opt

-- Line numbers
opt.number = true
opt.relativenumber = true

-- Tabs & indentation
opt.tabstop = 2
opt.shiftwidth = 2
opt.expandtab = true
opt.autoindent = true
opt.smartindent = true

-- Line wrapping
opt.wrap = false

-- Search
opt.ignorecase = true
opt.smartcase = true
opt.hlsearch = true
opt.incsearch = true

-- Appearance
opt.termguicolors = true
opt.background = "dark"
opt.signcolumn = "yes"
opt.cursorline = true
opt.scrolloff = 8
opt.numberwidth = 4

-- Splits
opt.splitright = true
opt.splitbelow = true

-- System clipboard integration
opt.clipboard:append("unnamedplus")

-- Files
opt.swapfile = false
opt.backup = false
opt.undofile = true
opt.undodir = vim.fn.stdpath("data") .. "/undodir"

-- Behavior
opt.backspace = "indent,eol,start"
opt.updatetime = 250
opt.timeoutlen = 300
opt.mouse = "a"
opt.completeopt = "menuone,noselect"
EOF

# -----------------------------------------------------------------------
# 6. core/keymaps.lua
# -----------------------------------------------------------------------
cat << 'EOF' > "$NVIM_CONFIG/lua/core/keymaps.lua"
local keymap = vim.keymap.set
local opts = { noremap = true, silent = true }

-- General
keymap("n", "<leader>w", ":w<CR>", opts)
keymap("n", "<leader>q", ":q<CR>", opts)
keymap("n", "<leader>Q", ":qa!<CR>", opts)
keymap("n", "<leader>nh", ":nohl<CR>", opts)
keymap("n", "x", '"_x', opts) -- delete char without yanking

-- Window movement
keymap("n", "<C-h>", "<C-w>h", opts)
keymap("n", "<C-j>", "<C-w>j", opts)
keymap("n", "<C-k>", "<C-w>k", opts)
keymap("n", "<C-l>", "<C-w>l", opts)

-- Window resizing
keymap("n", "<C-Up>", ":resize -2<CR>", opts)
keymap("n", "<C-Down>", ":resize +2<CR>", opts)
keymap("n", "<C-Left>", ":vertical resize -2<CR>", opts)
keymap("n", "<C-Right>", ":vertical resize +2<CR>", opts)

-- Split management
keymap("n", "<leader>sv", "<C-w>v", opts)
keymap("n", "<leader>sh", "<C-w>s", opts)
keymap("n", "<leader>se", "<C-w>=", opts)
keymap("n", "<leader>sx", ":close<CR>", opts)

-- Buffer navigation
keymap("n", "<S-l>", ":bnext<CR>", opts)
keymap("n", "<S-h>", ":bprevious<CR>", opts)
keymap("n", "<leader>bd", ":bdelete<CR>", opts)

-- Move selected lines up/down
keymap("v", "<A-j>", ":m .+1<CR>==", opts)
keymap("v", "<A-k>", ":m .-2<CR>==", opts)

-- Stay in indent mode
keymap("v", "<", "<gv", opts)
keymap("v", ">", ">gv", opts)

-- File explorer
keymap("n", "<leader>e", ":NvimTreeToggle<CR>", opts)

-- Telescope
keymap("n", "<leader>ff", ":Telescope find_files<CR>", opts)
keymap("n", "<leader>fg", ":Telescope live_grep<CR>", opts)
keymap("n", "<leader>fb", ":Telescope buffers<CR>", opts)
keymap("n", "<leader>fh", ":Telescope help_tags<CR>", opts)
EOF

# -----------------------------------------------------------------------
# 7. core/lazy.lua (lazy.nvim bootstrap)
# -----------------------------------------------------------------------
cat << 'EOF' > "$NVIM_CONFIG/lua/core/lazy.lua"
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
  vim.fn.system({
    "git",
    "clone",
    "--filter=blob:none",
    "https://github.com/folke/lazy.nvim.git",
    "--branch=stable",
    lazypath,
  })
end
vim.opt.rtp:prepend(lazypath)

require("lazy").setup("plugins", {
  install = { colorscheme = { "catppuccin" } },
  checker = { enabled = false },
  change_detection = { notify = false },
})
EOF

# -----------------------------------------------------------------------
# 8. plugins/ui.lua (colorscheme, statusline, tabline, which-key)
# -----------------------------------------------------------------------
cat << 'EOF' > "$NVIM_CONFIG/lua/plugins/ui.lua"
return {
  {
    "catppuccin/nvim",
    name = "catppuccin",
    priority = 1000,
    config = function()
      require("catppuccin").setup({
        flavour = "mocha",
        transparent_background = false,
        integrations = {
          cmp = true,
          gitsigns = true,
          nvimtree = true,
          telescope = true,
          treesitter = true,
          which_key = true,
        },
      })
      vim.cmd.colorscheme("catppuccin")
    end,
  },
  {
    "nvim-lualine/lualine.nvim",
    dependencies = { "nvim-tree/nvim-web-devicons" },
    config = function()
      require("lualine").setup({
        options = {
          theme = "catppuccin",
          globalstatus = true,
          section_separators = "",
          component_separators = "|",
        },
      })
    end,
  },
  {
    "akinsho/bufferline.nvim",
    version = "*",
    dependencies = { "nvim-tree/nvim-web-devicons" },
    config = function()
      require("bufferline").setup({
        options = {
          diagnostics = "nvim_lsp",
          separator_style = "slant",
          always_show_bufferline = true,
          offsets = {
            {
              filetype = "NvimTree",
              text = "File Explorer",
              highlight = "Directory",
              text_align = "left",
            },
          },
        },
      })
    end,
  },
  {
    "folke/which-key.nvim",
    event = "VeryLazy",
    config = function()
      require("which-key").setup({})
    end,
  },
}
EOF

# -----------------------------------------------------------------------
# 9. plugins/telescope.lua
# -----------------------------------------------------------------------
cat << 'EOF' > "$NVIM_CONFIG/lua/plugins/telescope.lua"
return {
  "nvim-telescope/telescope.nvim",
  branch = "0.1.x",
  dependencies = {
    "nvim-lua/plenary.nvim",
    "nvim-tree/nvim-web-devicons",
  },
  config = function()
    require("telescope").setup({
      defaults = {
        prompt_prefix = " ",
        selection_caret = " ",
        file_ignore_patterns = { "node_modules", ".git/" },
        mappings = {
          i = {
            ["<C-j>"] = "move_selection_next",
            ["<C-k>"] = "move_selection_previous",
          },
        },
      },
    })
  end,
}
EOF

# -----------------------------------------------------------------------
# 10. plugins/nvim-tree.lua
# -----------------------------------------------------------------------
cat << 'EOF' > "$NVIM_CONFIG/lua/plugins/nvim-tree.lua"
return {
  "nvim-tree/nvim-tree.lua",
  dependencies = { "nvim-tree/nvim-web-devicons" },
  config = function()
    require("nvim-tree").setup({
      view = { width = 30 },
      renderer = { group_empty = true, highlight_git = true },
      filters = { dotfiles = false },
      git = { enable = true },
      actions = {
        open_file = {
          window_picker = { enable = false },
        },
      },
    })
  end,
}
EOF

# -----------------------------------------------------------------------
# 11. plugins/editor.lua (autopairs, Comment.nvim, gitsigns)
# -----------------------------------------------------------------------
cat << 'EOF' > "$NVIM_CONFIG/lua/plugins/editor.lua"
return {
  {
    "windwp/nvim-autopairs",
    event = "InsertEnter",
    config = function()
      require("nvim-autopairs").setup({})
    end,
  },
  {
    "numToStr/Comment.nvim",
    config = function()
      require("Comment").setup()
    end,
  },
  {
    "lewis6991/gitsigns.nvim",
    config = function()
      require("gitsigns").setup({
        signs = {
          add = { text = "+" },
          change = { text = "~" },
          delete = { text = "_" },
          topdelete = { text = "‾" },
          changedelete = { text = "~" },
        },
      })
    end,
  },
}
EOF

# -----------------------------------------------------------------------
# 12. plugins/treesitter.lua
# -----------------------------------------------------------------------
cat << 'EOF' > "$NVIM_CONFIG/lua/plugins/treesitter.lua"
return {
  "nvim-treesitter/nvim-treesitter",
  build = ":TSUpdate",
  config = function()
    require("nvim-treesitter.configs").setup({
      ensure_installed = {
        "c", "cpp", "python", "lua", "bash",
        "markdown", "markdown_inline", "vim", "vimdoc",
      },
      sync_install = false,
      auto_install = true,
      highlight = { enable = true },
      indent = { enable = true },
    })
  end,
}
EOF

# -----------------------------------------------------------------------
# 13. plugins/lsp.lua (Mason, mason-lspconfig, lspconfig, cmp, LuaSnip)
# -----------------------------------------------------------------------
cat << 'EOF' > "$NVIM_CONFIG/lua/plugins/lsp.lua"
return {
  {
    "williamboman/mason.nvim",
    config = function()
      require("mason").setup({
        ui = { border = "rounded" },
      })
    end,
  },
  {
    "williamboman/mason-lspconfig.nvim",
    dependencies = { "williamboman/mason.nvim" },
    config = function()
      require("mason-lspconfig").setup({
        ensure_installed = { "clangd", "pyright", "bashls", "lua_ls" },
      })
    end,
  },
  {
    "neovim/nvim-lspconfig",
    dependencies = {
      "williamboman/mason.nvim",
      "williamboman/mason-lspconfig.nvim",
      "hrsh7th/cmp-nvim-lsp",
    },
    config = function()
      local lspconfig = require("lspconfig")
      local capabilities = require("cmp_nvim_lsp").default_capabilities()

      local on_attach = function(_, bufnr)
        local o = { noremap = true, silent = true, buffer = bufnr }
        vim.keymap.set("n", "gd", vim.lsp.buf.definition, o)
        vim.keymap.set("n", "gD", vim.lsp.buf.declaration, o)
        vim.keymap.set("n", "gi", vim.lsp.buf.implementation, o)
        vim.keymap.set("n", "gr", vim.lsp.buf.references, o)
        vim.keymap.set("n", "K", vim.lsp.buf.hover, o)
        vim.keymap.set("n", "<leader>ca", vim.lsp.buf.code_action, o)
        vim.keymap.set("n", "<leader>rn", vim.lsp.buf.rename, o)
        vim.keymap.set("n", "<leader>D", vim.lsp.buf.type_definition, o)
        vim.keymap.set("n", "[d", vim.diagnostic.goto_prev, o)
        vim.keymap.set("n", "]d", vim.diagnostic.goto_next, o)
        vim.keymap.set("n", "<leader>d", vim.diagnostic.open_float, o)
        vim.keymap.set("n", "<leader>fo", function()
          vim.lsp.buf.format({ async = true })
        end, o)
      end

      lspconfig.clangd.setup({
        capabilities = capabilities,
        on_attach = on_attach,
      })

      lspconfig.pyright.setup({
        capabilities = capabilities,
        on_attach = on_attach,
      })

      lspconfig.bashls.setup({
        capabilities = capabilities,
        on_attach = on_attach,
      })

      lspconfig.lua_ls.setup({
        capabilities = capabilities,
        on_attach = on_attach,
        settings = {
          Lua = {
            diagnostics = { globals = { "vim" } },
            workspace = {
              checkThirdParty = false,
              library = { vim.env.VIMRUNTIME },
            },
            telemetry = { enable = false },
          },
        },
      })

      vim.diagnostic.config({
        virtual_text = true,
        signs = true,
        underline = true,
        update_in_insert = false,
        severity_sort = true,
      })
    end,
  },
  {
    "hrsh7th/nvim-cmp",
    dependencies = {
      "hrsh7th/cmp-nvim-lsp",
      "hrsh7th/cmp-buffer",
      "hrsh7th/cmp-path",
      "L3MON4D3/LuaSnip",
      "saadparwaiz1/cmp_luasnip",
      "rafamadriz/friendly-snippets",
    },
    config = function()
      local cmp = require("cmp")
      local luasnip = require("luasnip")
      require("luasnip.loaders.from_vscode").lazy_load()

      cmp.setup({
        snippet = {
          expand = function(args)
            luasnip.lsp_expand(args.body)
          end,
        },
        window = {
          completion = cmp.config.window.bordered(),
          documentation = cmp.config.window.bordered(),
        },
        mapping = cmp.mapping.preset.insert({
          ["<C-b>"] = cmp.mapping.scroll_docs(-4),
          ["<C-f>"] = cmp.mapping.scroll_docs(4),
          ["<C-Space>"] = cmp.mapping.complete(),
          ["<C-e>"] = cmp.mapping.abort(),
          ["<CR>"] = cmp.mapping.confirm({ select = true }),
          ["<Tab>"] = cmp.mapping(function(fallback)
            if cmp.visible() then
              cmp.select_next_item()
            elseif luasnip.expand_or_jumpable() then
              luasnip.expand_or_jump()
            else
              fallback()
            end
          end, { "i", "s" }),
          ["<S-Tab>"] = cmp.mapping(function(fallback)
            if cmp.visible() then
              cmp.select_prev_item()
            elseif luasnip.jumpable(-1) then
              luasnip.jump(-1)
            else
              fallback()
            end
          end, { "i", "s" }),
        }),
        sources = cmp.config.sources({
          { name = "nvim_lsp" },
          { name = "luasnip" },
        }, {
          { name = "buffer" },
          { name = "path" },
        }),
      })
    end,
  },
}
EOF

# -----------------------------------------------------------------------
# 14. Bootstrap plugins + treesitter parsers headlessly
# -----------------------------------------------------------------------
echo "==> Syncing plugins headlessly (this can take a minute)..."
nvim --headless "+Lazy! sync" +qa

echo "==> Installing Treesitter parsers..."
nvim --headless "+TSUpdateSync" +qa

echo ""
echo "======================================================"
echo "  Setup complete!"
echo "======================================================"
echo "Launch Neovim with:  nvim"
echo ""
echo "Notes:"
echo "  - Mason will finish installing LSP servers (clangd, pyright,"
echo "    bash-language-server, lua-language-server) shortly after your"
echo "    first real launch. Run :Mason to watch progress."
echo "  - Run 'source ~/.bashrc' (or restart your shell) so the"
echo "    ~/.local/bin PATH update (needed for the fd symlink) takes effect."
echo "  - Leader key is <Space>. Try <Space>ff (find files), <Space>fg"
echo "    (live grep), <Space>e (file tree), <Space>ff, K (hover docs),"
echo "    gd (go to definition), <Space>ca (code actions), <Space>rn (rename)."

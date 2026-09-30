#!/usr/bin/env bash
# ╔══════════════════════════════════════════════╗
# ║  KANG 2.0 — animated terminal banner         ║
# ║  usage: banner.sh [-f|--fast]  (skip anim)   ║
# ╚══════════════════════════════════════════════╝

[[ ${LANG:-} == *UTF-8* || ${LC_ALL:-} == *UTF-8* ]] || export LC_ALL=C.UTF-8

FAST=0
[[ $1 == -f || $1 == --fast || -n $KANG_FAST ]] && FAST=1

RST=$'\033[0m'; BOLD=$'\033[1m'; DIM=$'\033[2m'
C=$'\033[38;2;0;210;255m'      # cyan
G=$'\033[38;2;80;250;140m'     # green
W=$'\033[38;2;235;235;250m'    # soft white
P=$'\033[38;2;150;110;255m'    # purple

PUT()        { printf '\033[%d;%dH' "$1" "$2"; }
HIDECURSOR() { printf '\033[?25l'; }
NORM()       { printf '\033[?12l\033[?25h'; }
trap 'NORM; printf "%s" "$RST"' EXIT INT TERM

# ── 64-step rainbow palette (truecolor), generated once ─────────
PAL=()
while read -r r g b; do
    PAL+=($'\033[38;2;'"${r};${g};${b}m")
done < <(awk 'BEGIN{for(i=0;i<64;i++){t=i*6.28318/64;
    printf "%d %d %d\n",150+105*sin(t),150+105*sin(t+2.094),150+105*sin(t+4.188)}}')
NP=${#PAL[@]}

# gradient text: gradtxt "text" phase
gradtxt() {
    local s=$1 off=$2 i out=
    for ((i=0; i<${#s}; i++)); do
        out+="${PAL[(i*2+off)%NP]}${s:i:1}"
    done
    printf '%s%s' "$out" "$RST"
}

# gradient horizontal line: hline left mid right phase
hline() {
    local out="${PAL[$4%NP]}$1" i
    for ((i=0; i<width-2; i++)); do out+="${PAL[(i+$4)%NP]}$2"; done
    out+="${PAL[(width+$4)%NP]}$3"
    printf '%s%s' "$out" "$RST"
}

# usage bar: bar percent
bar() {
    local n=20 f=$(( $1 * 20 / 100 )) i out=
    (( f > n )) && f=$n
    for ((i=0; i<n; i++)); do
        if (( i < f )); then
            out+=$'\033[38;2;'"$((60+195*i/(n-1)));$((220-150*i/(n-1)));90m▰"
        else
            out+=$'\033[38;2;55;55;70m▱'
        fi
    done
    printf '%s%s' "$out" "$RST"
}

# ── logo ────────────────────────────────────────────────────────
LOGO=(
"██╗  ██╗ █████╗   ███╗   ██╗ ██████╗ "
"██║ ██╔╝ ██╔══██╗ ████╗  ██║ ██╔════╝"
"█████═╝  ███████║ ██╔██╗ ██║ ██║  ██╗"
"██╔═██╗  ██╔══██║ ██║╚██╗██║ ██║  ╚██╗"
"██║ ╚██╗ ██║  ██║ ██║ ╚████║ ╚██████╔╝"
"╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝  ╚═══╝  ╚═════╝ "
)
LW=38
GL=(░ ▒ ▓ █ ╬ ╪ ▚ ▞)

# draw_logo phase reveal  (reveal=999 → fully shown; glitch edge while revealing)
draw_logo() {
    local ph=$1 rev=$2 row i ch out line
    for row in 0 1 2 3 4 5; do
        line=${LOGO[row]}; out=
        for ((i=0; i<${#line}; i++)); do
            ch=${line:i:1}
            if [[ $ch == ' ' ]]; then out+=' '
            elif (( i < rev )); then out+="${PAL[(i*2+row*3+ph)%NP]}$ch"
            elif (( i < rev+3 )); then out+="${W}${GL[RANDOM%8]}"
            else out+=' '
            fi
        done
        PUT $((4+row)) "$sc"; printf '%s%s' "$out" "$RST"
    done
}

draw_frame() {   # draw_frame phase
    local ph=$1 r
    PUT 2 1;  hline ╔ ═ ╗ "$ph"
    PUT 12 1; hline ╚ ═ ╝ $((ph+32))
    for ((r=3; r<=11; r++)); do
        PUT $r 1;      printf '%s║%s' "${PAL[(r*4+ph)%NP]}" "$RST"
        PUT $r "$width"; printf '%s║%s' "${PAL[(r*4+ph+32)%NP]}" "$RST"
    done
}

# ── system info ─────────────────────────────────────────────────
collect() {
    host="${USER:-$(id -un)}@$(hostname -s 2>/dev/null || hostname)"
    os=$(. /etc/os-release 2>/dev/null && echo "$PRETTY_NAME"); os=${os:-$(uname -s)}
    kern=$(uname -sr)
    up=$(uptime -p 2>/dev/null | sed 's/^up //'); up=${up:-$(uptime | sed 's/.*up \([^,]*\),.*/\1/')}
    shl=${SHELL##*/}

    cores=$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 1)
    load=$(cut -d' ' -f1 /proc/loadavg 2>/dev/null || uptime | sed 's/.*load averages*: *//' | awk '{print $1}' | tr -d ,)
    cpup=$(awk -v l="${load:-0}" -v c="$cores" 'BEGIN{p=l*100/c; if(p>100)p=100; printf "%d",p}')

    read -r mu mt < <(free -m 2>/dev/null | awk '/^Mem:/{print $3, $2}')
    mu=${mu:-0}; mt=${mt:-0}
    (( mt > 0 )) && memp=$((mu*100/mt)) || memp=0

    read -r dtot dused dpct < <(df -h "$HOME" 2>/dev/null | awk 'NR==2{print $2, $3, $5}')
    dpct=${dpct//%/}; dpct=${dpct:-0}; dtot=${dtot:-?}; dused=${dused:-?}
}

say() { printf '%s\n' "$*"; (( FAST )) || sleep 0.035; }
kv()  { say "  ${P}◆ ${C}$(printf '%-7s' "$1")${W} $2"; }
mt()  { say "  ${P}◆ ${C}$(printf '%-7s' "$1") $(bar "$2") ${W}$(printf '%3d' "$2")%${DIM}  $3${RST}"; }

# ── main ────────────────────────────────────────────────────────
main() {
    command clear
    width=$(tput cols 2>/dev/null || echo 80); (( width < 44 )) && width=44
    sc=$(( (width - LW) / 2 )); (( sc < 2 )) && sc=2
    collect
    HIDECURSOR

    # title bar
    local t="${host} — ${shl}"
    PUT 1 1; printf ' \033[91m●\033[93m●\033[92m● %s' "$RST"
    PUT 1 $(( (width - ${#t}) / 2 )); printf '%s%s%s' "$DIM" "$t" "$RST"

    # animated reveal + shimmer
    local rev ph=0
    if (( FAST )); then
        draw_frame 0; draw_logo 0 999
    else
        for ((rev=0; rev<=LW+2; rev+=2)); do
            draw_frame "$rev"; draw_logo "$rev" "$rev"; sleep 0.015
        done
        for ((ph=0; ph<48; ph+=2)); do
            draw_frame "$ph"; draw_logo "$ph" 999; sleep 0.025
        done
    fi

    local tag="[ KANG 2.0 ]"
    PUT 10 $(( width - ${#tag} - 2 )); gradtxt "$tag" "$ph"
    local sub="▸  s y s t e m   o n l i n e  ◂"
    PUT 11 $(( (width - ${#sub}) / 2 )); gradtxt "$sub" $((ph+10))

    # greeting + clock
    local h; h=$((10#$(date +%H)))
    local greet="Good evening"
    (( h < 12 )) && greet="Good morning"
    (( h >= 12 && h < 17 )) && greet="Good afternoon"
    PUT 14 1
    say "  ${BOLD}$(gradtxt "$greet, ${USER:-$(id -un)}." $((ph+20)))"
    say "  ${G}◷ ${C}$(date '+%I:%M:%S') ${G}— ${C}$(date '+%p')  ${G}│  ${G}▣ ${C}$(date '+%A, %d %B %Y')"
    say ""
    say "  $(gradtxt '━━━━━━━━  S Y S T E M  ━━━━━━━━' 8)"
    kv "user"   "$host"
    kv "os"     "$os"
    kv "kernel" "$kern"
    kv "uptime" "$up"
    say ""
    mt "cpu"  "$cpup" "load ${load:-?} · ${cores} cores"
    mt "mem"  "$memp" "${mu}M / ${mt}M"
    mt "disk" "$dpct" "${dused} of ${dtot}"
    say ""
    NORM
}

main

#include <stdio.h>

int main()
{
    char s[200], res[200];
    int i = 0, j = 0;
    fgets(s, sizeof(s), stdin);
    while (s[i] != '\0')
    {
        if ((s[i] == 't' || s[i] == 'T') && (s[i + 1] == 'h' || s[i + 1] == 'H') &&
            (s[i + 2] == 'e' || s[i + 2] == 'E') && (i == 0 || s[i - 1] == ' ') &&
            (s[i + 3] == ' ' || s[i + 3] == '\0' || s[i + 3] == '\n'))
        {
            i += 3;
            if (s[i] == ' ')
            {
                i++;
            }
        }
        else
        {
            res[j++] = s[i++];
        }
    }
    res[j] = '\0';
    printf("%s", res);
    return 0;
}

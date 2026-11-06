#include <stdio.h>

int main()
{
    char s[81], res[81];
    int i, j = 0;
    fgets(s, sizeof(s), stdin);
    for (i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'A' && c != 'E' && c != 'I' && c != 'O' &&
            c != 'U')
        {
            res[j++] = c;
        }
    }
    res[j] = '\0';
    printf("%s", res);
    return 0;
}

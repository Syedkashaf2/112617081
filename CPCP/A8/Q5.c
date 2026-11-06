#include <stdio.h>

int isVowel(char c)
{
    if (c >= 'A' && c <= 'Z')
        c = c + 32;
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
    char s[200];
    int i, count = 0;
    fgets(s, sizeof(s), stdin);
    for (i = 0; s[i] != '\0' && s[i + 1] != '\0'; i++)
    {
        if (isVowel(s[i]) && isVowel(s[i + 1]))
        {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}

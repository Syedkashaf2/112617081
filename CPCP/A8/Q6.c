#include <stdio.h>

int main() {
    char s[100], sub[100];
    int pos, len, i, j = 0;
    fgets(s, sizeof(s), stdin);
    scanf("%d %d", &pos, &len);

    int start = pos - 1;
    if (len == 0) {
        while (s[start] != '\0' && s[start] != '\n') {
            sub[j++] = s[start++];
        }
    } else {
        for (i = 0; i < len && s[start] != '\0' && s[start] != '\n'; i++) {
            sub[j++] = s[start++];
        }
    }
    sub[j] = '\0';
    printf("%s\n", sub);
    return 0;
}

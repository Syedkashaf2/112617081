#include <stdio.h>

int main() {
    int i;

    for (i = 0; i < 2000; i++) {
        if (i % 2 == 0) {
            printf("%c", 4);
        } else {
            printf("%c", 3);
        }
    }

    return 0;
}

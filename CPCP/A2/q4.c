#include <stdio.h>

int main() {
    char gen, qual;
    int yos, sal;

    printf("Enter gender m/f, years, qualification g/p: ");
    scanf(" %c %d %c", &gen, &yos, &qual);

    if (gen == 'm' || gen == 'M') {
        if (yos >= 10) {
            if (qual == 'p' || qual == 'P') {
                sal = 15000;
            } else {
                sal = 10000;
            }
        } else {
            if (qual == 'p' || qual == 'P') {
                sal = 10000;
            } else {
                sal = 7000;
            }
        }
    } else {
        if (yos >= 10) {
            if (qual == 'p' || qual == 'P') {
                sal = 12000;
            } else {
                sal = 9000;
            }
        } else {
            if (qual == 'p' || qual == 'P') {
                sal = 10000;
            } else {
                sal = 6000;
            }
        }
    }

    printf("Salary = %d\n", sal);
    return 0;


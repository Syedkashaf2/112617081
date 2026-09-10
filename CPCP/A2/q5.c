#include <stdio.h>

int main() {
    char ms, sex;
    int age;

    printf("Enter marital status (m/u), sex (m/f), age: ");
    scanf(" %c %c %d", &ms, &sex, &age);

    if (ms == 'm' || ms == 'M') {
        printf("Driver is insured\n");
    } else if ((sex == 'm' || sex == 'M') && age > 30) {
        printf("Driver is insured\n");
    } else if ((sex == 'f' || sex == 'F') && age > 25) {
        printf("Driver is insured\n");
    } else {
        printf("Driver is not insured\n");
    }

    return 0;
}

#include <stdio.h>


double add(double a, double b) {
    return (a + b);
}

double subtract(double a, double b) {
    return (a - b);
}

double multiply(double a, double b) {
    return (a * b);
}

double divide(double a, double b) {
    if (b == 0) {
        printf("Ошибка: Нельзя делить на ноль.\n");
        return 0.0;
    }
    return ((double)a / (double)b);
}

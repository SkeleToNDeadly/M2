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
        return 0;
    }
    return (a / b);
}

int main() {
    int choice;
    double num1, num2; 

    do {
        printf("Меню калькулятора:\n");
        printf("1. Сложение\n");
        printf("2. Разность\n");
        printf("3. Умножение\n");
        printf("4. Деление\n");
        printf("5. Выход\n");
        printf("Введите ваш выбор (1-5): ");
        scanf("%d", &choice); 

        if (choice >= 1 && choice <= 4) {
            printf("Введите первое число: ");
            scanf("%lf", &num1);
            printf("Введите второе число: ");
            scanf("%lf", &num2);
        }

        switch (choice) {
            case 1:
                printf("Результат: %lf + %lf = %lf\n", num1, num2, add(num1, num2));
                break;
            case 2:
                printf("Результат: %lf - %lf = %lf\n", num1, num2, subtract(num1, num2));
                break;
            case 3:
                printf("Результат: %lf * %lf = %lf\n", num1, num2, multiply(num1, num2));
                break;
            case 4:
                printf("Результат: %lf / %lf = %lf\n", num1, num2, divide(num1, num2));
                break;
            case 5:
                printf("Выход из калькулятора.\n");
                break;
            default:
                printf("Неправленьный выбор. Пожалуйста попробуйте снова.\n");
        }
    } while (choice != 5);

    return 0;
}

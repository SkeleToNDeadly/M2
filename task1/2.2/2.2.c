#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("Ошибка: Нельзя делить на ноль.\n");
        return 0;
    }
    return a / b;
}

int main() {
    int choice;
    int num1, num2;

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
            scanf("%d", &num1);
            printf("Введите второе число: ");
            scanf("%d", &num2);
        }

        switch (choice) {
            case 1:
                printf("Результат: %d + %d = %d\n", num1, num2, add(num1, num2));
                break;
            case 2:
                printf("Результат: %d - %d = %d\n", num1, num2, subtract(num1, num2));
                break;
            case 3:
                printf("Результат: %d * %d = %d\n", num1, num2, multiply(num1, num2));
                break;
            case 4:
                printf("Результат: %d / %d = %d\n", num1, num2, divide(num1, num2));
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

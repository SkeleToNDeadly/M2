#include <stdio.h>
#include <dlfcn.h>

int main() {
    void* handle = dlopen("./calc.so", RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "Не удалось загрузить библиотеку: %s\n", dlerror());
        return 1;
    }

    int (*add)(int, int) = dlsym(handle, "add");
    int (*subtract)(int, int) = dlsym(handle, "subtract");
    int (*multiply)(int, int) = dlsym(handle, "multiply");
    int (*divide)(int, int) = dlsym(handle, "divide");

    if (!add || !subtract || !multiply || !divide) {
        fprintf(stderr, "Ошибка загрузки функций: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    int choice;
    int num1, num2;

    do {
        printf("Меню калькулятора:\n");
        printf("1. Сложение\n");
        printf("2. Разность\n");
        printf("3. Умножение\n");
        printf("4. Деление\n");
        printf("5. Выход\n");
        printf("Ваш выбор (1-5): ");
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
                printf("Неправильный выбор. Пожалуйста, попробуйте снова.\n");
        }
    } while (choice != 5);

return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_LN_LENGTH 50
#define MAX_WORK_LENGTH 100
#define MAX_POS_LENGTH 100
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define MAX_SOCIAL_LENGTH 50

struct Contact {
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_LN_LENGTH];
    char work_place[MAX_WORK_LENGTH];
    char position[MAX_POS_LENGTH];
    char phone_numbers[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char social_links[MAX_SOCIAL_LENGTH];
};

struct Contact* contacts = NULL;
int contactCount = 0;
int maxContacts = 0;

void addContact() {
    struct Contact newContact;

    if (contactCount >= maxContacts) {
        // Если динамический массив заполнен, удвоить его размер
        maxContacts = (maxContacts == 0) ? 1 : maxContacts * 2;
        contacts = (struct Contact*)realloc(contacts, maxContacts * sizeof(struct Contact));
        if (contacts == NULL) {
            printf("Не удалось выделить память. Невозможно добавить новый контакт.\n");
            return;
        }
    }

    do {
        printf("Введите свое имя ");
    } while (scanf("%49s", newContact.first_name) != 1);

    do {
        printf("Введите свою фамилию: ");
    } while (scanf("%49s", newContact.last_name) != 1);

    printf("Введите место вашей работы: ");
    scanf("%99s", newContact.work_place);
    printf("Введите свою должность: ");
    scanf("%99s", newContact.position);
    printf("Введите свой номер телефона: ");
    scanf("%19s", newContact.phone_numbers);
    printf("Введите свой email: ");
    scanf("%49s", newContact.email);
    printf("Введи ссылку на соц.сеть: ");
    scanf("%49s", newContact.social_links);

    contacts[contactCount++] = newContact;
    printf("Контакт добавлен успешно!\n");
}

void displayContacts() {
    printf("КОНТАКТЫ В ТЕЛЕФОННОЙ КНИГЕ:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Контакт %d:\n", i + 1);
        printf("Имя: %s\n", contacts[i].first_name);
        printf("Фамилия: %s\n", contacts[i].last_name);
        printf("Месито работы: %s\n", contacts[i].work_place);
        printf("Должность: %s\n", contacts[i].position);
        printf("Телефон: %s\n", contacts[i].phone_numbers);
        printf("Email: %s\n", contacts[i].email);
        printf("Соц.сеть: %s\n", contacts[i].social_links);
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("Телефонная книга:\n");
        printf("1. Добавить контакт\n");
        printf("2. Показать существующие контакты\n");
        printf("3. Выход\n");
        printf("Введите ваш выбор: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                printf("Выход из телефонной книги.\n");
                break;
            default:
                printf("Вы ввели недопустимый выбор. Пожалуйста попробуйте ещё раз.\n");
        }
    } while (choice != 3);

    free(contacts); // Освободить динамически выделенную память
    return 0;
}

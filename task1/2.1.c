#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_WORK_LENGTH 100
#define MAX_POS_LENGTH 100
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define MAX_SOCIAL_LENGTH 50

struct Contact {
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    char work_place[MAX_WORK_LENGTH];
    char position[MAX_POS_LENGTH];
    char phone_numbers[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char social_links[MAX_SOCIAL_LENGTH];
};

struct Contact contacts[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount < MAX_CONTACTS) {
        struct Contact newContact;
        printf("Введите ваше имя: ");
        scanf("%s", newContact.first_name);
        printf("Введите вашу фамилию: ");
        scanf("%s", newContact.last_name);
        printf("Введите ваше место работы: ");
        scanf("%s", newContact.work_place);
        printf("Введите вашу должность: ");
        scanf("%s", newContact.position);
        printf("Введите телефонный номер: ");
        scanf("%s", newContact.phone_numbers);
        printf("Введите email: ");
        scanf("%s", newContact.email);
        printf("Введите ссылку на соц.сети: ");
        scanf("%s", newContact.social_links);
        contacts[contactCount++] = newContact;
        printf("Контакт был добавлен успешно!\n");
    } else {
        printf("Телефонная книга запелнена. Невозможно добавить больше контактов.\n");
    }
}

void displayContacts() {
    printf("Контакты в телефонной книге:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Контакты %d:\n", i + 1);
        printf("Имя: %s\n", contacts[i].first_name);
        printf("Фамилия: %s\n", contacts[i].last_name);
        printf("Место работы: %s\n", contacts[i].work_place);
        printf("Должность: %s\n", contacts[i].position);
        printf("Телефон: %s\n", contacts[i].phone_numbers);
        printf("Email: %s\n", contacts[i].email);
        printf("Ссыла на соц.сеть: %s\n", contacts[i].social_links);
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("Телефонная книга:\n");
        printf("1. Добавить  контакт\n");
        printf("2. Показать существующие\n");
        printf("3. Выйти\n");
        printf("Введите выше выбор: ");
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
                printf("Укан неверный выбор. Пожалуйста попробуйте ещё раз.\n");
        }
    } while (choice != 3);

    return 0;
}

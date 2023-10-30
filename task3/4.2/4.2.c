#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 255

struct PriorityItem {
    int data;
    int priority;
};

struct PriorityQueue {
    struct PriorityItem items[MAX_SIZE];
    int size;
};

// Инициализация очереди
void initQueue(struct PriorityQueue *queue) {
    queue->size = 0;
}

// Добавление элемента с приоритетом
void enqueue(struct PriorityQueue *queue, int data, int priority) {
    if (queue->size < MAX_SIZE) {
        struct PriorityItem newItem;
        newItem.data = data;
        newItem.priority = priority;
        int i = queue->size;
        while (i > 0 && newItem.priority < queue->items[i - 1].priority) {
            queue->items[i] = queue->items[i - 1];
            i--;
        }
        queue->items[i] = newItem;
        queue->size++;
    } else {
        printf("Очередь переполнена.\n");
    }
}

// Извлечение элемента с наивысшим приоритетом
int dequeue(struct PriorityQueue *queue) {
    if (queue->size > 0) {
        int data = queue->items[0].data;
        for (int i = 1; i < queue->size; i++) {
            queue->items[i - 1] = queue->items[i];
        }
        queue->size--;
        return data;
    } else {
        printf("Очередь пуста.\n");
        return -1;
    }
}

// Извлечение элемента с указанным приоритетом
int dequeueWithPriority(struct PriorityQueue *queue, int priority) {
    if (queue->size > 0) {
        for (int i = 0; i < queue->size; i++) {
            if (queue->items[i].priority == priority) {
                int data = queue->items[i].data;
                for (int j = i + 1; j < queue->size; j++) {
                    queue->items[j - 1] = queue->items[j];
                }
                queue->size--;
                return data;
            }
        }
        printf("Элемент с приоритетом %d не найден.\n", priority);
        return -1;
    } else {
        printf("Очередь пуста.\n");
        return -1;
    }
}

// Извлечение элемента с приоритетом не ниже указанного
int dequeueWithPriorityAtLeast(struct PriorityQueue *queue, int priority) {
    if (queue->size > 0) {
        for (int i = 0; i < queue->size; i++) {
            if (queue->items[i].priority >= priority) {
                int data = queue->items[i].data;
                for (int j = i + 1; j < queue->size; j++) {
                    queue->items[j - 1] = queue->items[j];
                }
                queue->size--;
                return data;
            }
        }
        printf("Элемент с приоритетом не ниже %d не найден.\n", priority);
        return -1;
    } else {
        printf("Очередь пуста.\n");
        return -1;
    }
}

int main() {
    struct PriorityQueue queue;
    initQueue(&queue);

    // Генерация сообщений с разными приоритетами и добавление их в очередь
    enqueue(&queue, 1, 2);
    enqueue(&queue, 2, 1);
    enqueue(&queue, 3, 3);
    enqueue(&queue, 4, 2);

    // Извлечение элементов с разными условиями приоритета
    printf("Извлечение элемента с наивысшим приоритетом: %d\n", dequeue(&queue));
    printf("Извлечение элемента с приоритетом 2: %d\n", dequeueWithPriority(&queue, 2));
    printf("Извлечение элемента с приоритетом не ниже 2: %d\n", dequeueWithPriorityAtLeast(&queue, 2));
    printf("Извлечение элемента с приоритетом не ниже 4: %d\n", dequeueWithPriorityAtLeast(&queue, 4));

    return 0;
}


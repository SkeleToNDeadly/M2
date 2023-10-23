#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_PACKETS 10000
#define MAX_IP_ADDRESSES 256

// Функция для генерации случайного IP-адреса
uint32_t generate_random_ip() {
    return (rand() << 24) | (rand() << 16) | (rand() << 8) | rand();
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Использование: %s <IP адрес шлюза> <Маска подсети> <Количество пакетов>\n", argv[0]);
        return 1;
    }

    struct in_addr gateway_ip;
    if (inet_pton(AF_INET, argv[1], &gateway_ip) != 1) {
        perror("Ошибка при разборе IP адреса шлюза");
        return 1;
    }

    uint32_t subnet_mask;
    if (sscanf(argv[2], "%u", &subnet_mask) != 1) {
        printf("Ошибка при разборе маски подсети\n");
        return 1;
    }

    int num_packets;
    if (sscanf(argv[3], "%d", &num_packets) != 1) {
        printf("Ошибка при разборе количества пакетов\n");
        return 1;
    }

    srand(time(NULL));
    uint32_t gateway_network = ntohl(gateway_ip.s_addr) & htonl(subnet_mask);
    int own_subnet_packets = 0;
    int other_subnet_packets = 0;
    int ip_address_count[MAX_IP_ADDRESSES] = {0};

    for (int i = 0; i < num_packets; i++) {
        uint32_t destination_ip = generate_random_ip();
        if ((destination_ip & subnet_mask) == gateway_network) {
            own_subnet_packets++;
        } else {
            other_subnet_packets++;
        }

        uint32_t dest_ip_host_byte = ntohl(destination_ip) & 0xFF;
        ip_address_count[dest_ip_host_byte]++;
    }

    printf("Статистика:\n");
    printf("Пакетов, предназначенных узлам в своей подсети: %d (%.2f%%)\n", own_subnet_packets,
           (float)own_subnet_packets / num_packets * 100);
    printf("Пакетов, предназначенных узлам в других сетях: %d (%.2f%%)\n", other_subnet_packets,
           (float)other_subnet_packets / num_packets * 100);
    printf("Список из 10 часто встречающихся адресов:\n");

    // Вывод адресов, сортированных по частоте
    for (int i = 0; i < MAX_IP_ADDRESSES; i++) {
        int max_count = 0;
        int max_index = 0;
        for (int j = 0; j < MAX_IP_ADDRESSES; j++) {
            if (ip_address_count[j] > max_count) {
                max_count = ip_address_count[j];
                max_index = j;
            }
        }
        ip_address_count[max_index] = 0;

        struct in_addr ip_addr;
        ip_addr.s_addr = htonl((gateway_network & subnet_mask) | (uint32_t)max_index);
        printf("%s\n", inet_ntoa(ip_addr));
    }

    return 0;
}


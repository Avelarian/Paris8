#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>

uint16_t calculateCrc(uint8_t *data, uint16_t length, uint16_t polynomial)
{
    uint16_t crc = 0xFFFF;
    for (int i = 0; i < length; i++)
    {
        crc = crc ^ (data[i] << 8);
        for (int j = 0; j < 8; j++)
        {
            if (crc & 0x8000)
            {
                crc = (crc << 1) ^ polynomial;
            }
            else
            {
                crc = crc << 1;
            }
        }
    }
    return crc;
}

typedef struct
{
    uint8_t *data;
    uint16_t length;
    uint16_t polynomial;
} RTS_CTS_Thread_Data;

void *RTS_send(void *arg)
{
    RTS_CTS_Thread_Data *thread_data = (RTS_CTS_Thread_Data *)arg;
    uint16_t crc = calculate_crc(thread_data->data, thread_data->length, thread_data->polynomial);

    printf("ENVOI DU RTS...\n");

    printf("EN ATTENTE DU CTS...\n");

    printf("ENVOIE DE DONNES AU CRC POUR VERIFICATION...\n");

    return NULL;
}

void *CTS_send(void *arg)
{
    RTS_CTS_Thread_Data *thread_data = (RTS_CTS_Thread_Data *)arg;

    printf("EN ATTENTE DU RTS...\n");

    printf("ENVOIE CTS...\n");

    printf("RECEPTION DE LA DONNEE ET DU CRC...\n");

    uint16_t crc = calculate_crc(thread_data->data, thread_data->length, thread_data->polynomial);

    if (crc == 0)
    {
        printf("DATA CORRECTE :) \n");
    }
    else
    {
        printf("DATA INCORRECTE :o \n");
    }

    return NULL;
}

int main()
{
    uint16_t length;
    printf("Enter the number of elements in the vector: ");
    scanf("%hu", &length);

    uint8_t *data = malloc(length * sizeof(uint8_t));
    if (data == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the binary elements of the vector: ");
    for (int i = 0; i < length; i++)
    {
        scanf("%hhu", &data[i]);
    }

    uint16_t polynomial;
    printf("Enter the polynomial: ");
    scanf("%hu", &polynomial);

    RTS_CTS_Thread_Data thread_data = {data, length, polynomial};

    pthread_t RTS_send_thread;
    pthread_t CTS_send_thread;

    pthread_create(&RTS_send_thread, NULL, RTS_send, &thread_data);
    pthread_create(&CTS_send_thread, NULL, CTS_send, &thread_data);

    pthread_join(RTS_send_thread, NULL);
    pthread_join(CTS_send_thread, NULL);

    free(data);

    return 0;
}
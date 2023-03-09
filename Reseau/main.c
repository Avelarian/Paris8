#include <stdio.h>

void calculeCRC(int message[], int tailleMessage, int polynome[], int taillePolynome, int crc[])
{
    int i, j;
    for (i = 0; i < tailleMessage; i++)
    {
        crc[i] = message[i];
    }
    for (i = 0; i < tailleMessage; i++)
    {
        if (crc[i] == 1)
        {
            for (j = 0; j < taillePolynome; j++)
            {
                crc[i + j] = crc[i + j] ^ polynome[j];
            }
        }
    }
    for (i = 0; i < taillePolynome - 1; i++)
    {
        crc[tailleMessage + i] = 0;
    }
}

int main()
{
    int message[100], polynome[100], crc[100], tailleMessage, taillePolynome, i;
    printf("Entrez la taille du message: ");
    scanf("%d", &tailleMessage);
    printf("Entrez le message: ");
    for (i = 0; i < tailleMessage; i++)
    {
        scanf("%d", &message[i]);
    }
    printf("Entrez la taille du polynome: ");
    scanf("%d", &taillePolynome);
    printf("Entrez le polynome: ");
    for (i = 0; i < taillePolynome; i++)
    {
        scanf("%d", &polynome[i]);
    }
    calculeCRC(message, tailleMessage, polynome, taillePolynome, crc);
    printf("Le message avec le CRC est: ");
    for (i = 0; i < tailleMessage + taillePolynome - 1; i++)
    {
        printf("%d", crc[i]);
    }
    printf("\n");
    return 0;
}
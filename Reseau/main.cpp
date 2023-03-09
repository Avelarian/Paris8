#include <iostream>
#include <pthread.h>
#include <vector>

struct Argument
{
    int debut;
    int fin;
    int *message;
    int *polynome;
    int taillePolynome;
    int *crc;
};

void *calculeCRC(void *arg)
{
    Argument *a = (Argument *)arg;
    int i, j;
    for (i = a->debut; i < a->fin; i++)
    {
        a->crc[i] = a->message[i];
    }
    for (i = a->debut; i < a->fin; i++)
    {
        if (a->crc[i] == 1)
        {
            for (j = 0; j < a->taillePolynome; j++)
            {
                a->crc[i + j] = a->crc[i + j] ^ a->polynome[j];
            }
        }
    }
    return NULL;
}

int main()
{
    int message[100], polynome[100], crc[100], tailleMessage, taillePolynome, i;
    std::cout << "Entrez la taille du message: ";
    std::cin >> tailleMessage;
    std::cout << "Entrez le message: ";
    for (i = 0; i < tailleMessage; i++)
    {
        std::cin >> message[i];
    }
    std::cout << "Entrez la taille du polynome: ";
    std::cin >> taillePolynome;
    std::cout << "Entrez le polynome: ";
    for (i = 0; i < taillePolynome; i++)
    {
        std::cin >> polynome[i];
    }
    int nbThreads = 4;
    int debut = 0;
    int fin = tailleMessage / nbThreads;
    std::vector<pthread_t> threads;
    std::vector<Argument> args;
    for (int i = 0; i < nbThreads; i++)
    {
        Argument a = {debut, fin, message, polynome, taillePolynome, crc};
        args.push_back(a);
        pthread_t t;
        pthread_create(&t, NULL, calculeCRC, &args[i]);
        threads.push_back(t);
        debut = fin;
        fin = (i == nbThreads - 2) ? tailleMessage : fin + tailleMessage / nbThreads;
    }
    for (auto &thread : threads)
    {
        pthread_join(thread, NULL);
    }
    std::cout << "Le message avec le CRC est: ";
    for (i = 0; i < tailleMessage + taillePolynome - 1; i++)
    {
        std::cout << crc[i];
    }
    std::cout << "\n";
    return 0;
}
#include <math.h>

double sigmoid(double value)
{
    return 1 / (1 + exp(-value));
}

double sigmoidDerivative(double value)
{
    return value * (1 - value);
}

double randomDouble()
{
    return (double)rand() / (double)RAND_MAX;
}

void shuffle(int *array, size_t arraySize)
{
    if (arraySize > 1)
    {
        for (size_t i = 0; i < arraySize - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (arraySize - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}
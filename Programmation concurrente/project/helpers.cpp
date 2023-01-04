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

bool compareStrings(char *string1, char *string2)
{
    int index = 0;
    while (string1[index] != '\0' && string2[index] != '\0')
    {
        if (string1[index] != string2[index])
        {
            return false;
        }
        index++;
    }
    return string1[index] == string2[index];
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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

int main()
{
    double x, y, w1, w2, b1, z;
    w1 = randomDouble();
    w2 = randomDouble();
    b1 = randomDouble();

    int trainingSetOrder[] = {0, 1, 2, 3};
    double trainingInputs[4][2] = {{0.0f, 0.0f}, {1.0f, 0.0f}, {0.0f, 1.0f}, {1.0f, 1.0f}};
    double trainingOutputs[4][1] = {{0.0f}, {0.0f}, {0.0f}, {1.0f}};

    for (int index; index < 100000; index++)
    {
        shuffle(trainingSetOrder, 4);

        for (int j = 0; j < 4; j++)
        {
            int i = trainingSetOrder[j];
            x = trainingInputs[i][0];
            y = trainingInputs[i][1];

            z = x * w1 + y * w2 + b1;
            double a = 1.0f / (1.0f + exp(-z));

            double error = trainingOutputs[i][0] - a;
            double delta = error * a * (1.0f - a);

            w1 += x * delta;
            w2 += y * delta;
            b1 += delta;
        }
    }

    printf("w1: %f w2: %f b1: %f ", w1, w2, b1);

    return 0;
}
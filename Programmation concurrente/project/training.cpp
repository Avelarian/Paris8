#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "helpers.cpp"

void *training(void *functionType)
{
    int inputs[4][2];
    int outputs[4];
    char *AND = "AND";
    char *XOR = "XOR";

    if (compareStrings(AND, (char *)functionType))
    {
        for (int i = 0; i <= 1; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                inputs[2 * i + j][0] = i;
                inputs[2 * i + j][1] = j;
                outputs[2 * i + j] = i && j;
            }
        }
    }
    else if (compareStrings(XOR, (char *)functionType))
    {
        for (int i = 0; i < 4; i++)
        {
            inputs[i][0] = i & 1;
            inputs[i][1] = i & 2;
            outputs[i] = (i & 1) ^ (i & 2);
        }
    }
    else
    {
        printf("Invalid function type");
        return (void *)1;
    }

    double weights[6];
    double bias[3];

    double firstLayer[2];
    double lastLayer;

    double results[4];

    int loopCount = 0;
    int trainingSetOrder[4] = {0, 1, 2, 3};

    for (int i = 0; i < 6; i++)
    {
        if (i < 3)
        {
            bias[i] = randomDouble();
        }
        weights[i] = randomDouble();
    }

    do
    {
        shuffle(trainingSetOrder, 4);

        for (int i = 0; i < 4; i++)
        {
            int trainingSetIndex = trainingSetOrder[i];

            for (int j = 0; j < 2; j++)
            {
                firstLayer[j] = bias[j];
                for (int k = 0; k < 2; k++)
                {
                    firstLayer[j] += inputs[trainingSetIndex][k] * weights[j * 2 + k];
                }
                firstLayer[j] = sigmoid(firstLayer[j]);
            }

            lastLayer = bias[2];
            for (int j = 0; j < 2; j++)
            {
                lastLayer += firstLayer[j] * weights[4 + j];
            }
            lastLayer = sigmoid(lastLayer);

            results[trainingSetIndex] = lastLayer;

            // TODO: Implement the batch gradient descent for correction of weights and bias;
            double deltaLastLayer = (outputs[trainingSetIndex] - lastLayer) * sigmoidDerivative(lastLayer);
            bias[2] += deltaLastLayer * 0.1;
            for (int j = 0; j < 2; j++)
            {
                double deltaFirstLayer = deltaLastLayer * weights[4 + j] * sigmoidDerivative(firstLayer[j]);
                for (int k = 0; k < 2; k++)
                {
                    weights[j * 2 + k] += deltaFirstLayer * inputs[trainingSetIndex][k] * 0.1;
                }
                bias[j] += deltaFirstLayer * 0.1;
                weights[4 + j] += deltaLastLayer * firstLayer[j] * 0.1;
            }
        }

        loopCount++;
    } while (loopCount < 10000);

    for (int trainingSetIndex = 0; trainingSetIndex < 4; trainingSetIndex++)
    {
        printf("INPUT 1: %d, INPUT 2: %d, OUTPUT: %f (EXPECTED: %d)\n", inputs[trainingSetIndex][0], inputs[trainingSetIndex][1], results[trainingSetIndex], outputs[trainingSetIndex]);
    }

    printf("FINAL FIRST LAYER WEIGHTS: %f, %f, %f, %f \n", weights[0], weights[1], weights[2], weights[3]);
    printf("FINAL FIRST LAYER BIAS: %f, %f \n", bias[0], bias[1]);

    printf("FINAL LAST LAYER WEIGHTS: %f, %f \n", weights[4], weights[5]);
    printf("FINAL LAST LAYER BIAS: %f \n", bias[2]);

    return (void *)0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <gradient.cpp>
#include <helpers.cpp>
#include <constants.cpp>

int main()
{
    int trainingSetOrder[] = {0, 1, 2, 3};

    double hiddenLayer[NUMBER_HIDDEN_NODES] = {randomDouble(), randomDouble()};
    double outputLayer[NUMBER_OUTPUTS];

    double hiddenLayerBias[NUMBER_HIDDEN_NODES];
    double outputLayerBias[NUMBER_OUTPUTS];

    double hiddenLayerWeights[NUMBER_INPUTS][NUMBER_HIDDEN_NODES];
    double outputLayerWeights[NUMBER_HIDDEN_NODES][NUMBER_OUTPUTS];

    double trainingInputs[NUMBER_TRIANING_SETS][NUMBER_INPUTS] = {{0.0f, 0.0f}, {1.0f, 0.0f}, {0.0f, 1.0f}, {1.0f, 1.0f}};
    double trainingOutputs[NUMBER_TRIANING_SETS][NUMBER_OUTPUTS] = {{0.0f}, {1.0f}, {1.0f}, {1.0f}};

    for (int i = 0; i < NUMBER_INPUTS; i++)
    {
        for (int j = 0; j < NUMBER_HIDDEN_NODES; j++)
        {
            hidden_layer_weights[i][j] = randomDoubleValue();
        }
    }
    for (int i = 0; i < NUMBER_HIDDEN_NODES; i++)
    {
        hidden_layer_bias[i] = randomDoubleValue();
        for (int j = 0; j < NUMBER_OUTPUTS; j++)
        {
            output_layer_weights[i][j] = randomDoubleValue();
        }
    }
    for (int i = 0; i < NUMBER_OUTPUTS; i++)
    {
        output_layer_bias[i] = randomDoubleValue();
    }

    for (int i = 0; i < LOOP_COUNT; i++)
    {
        /* Shuffle the training set to have a new combination on each loop */
        shuffle(training_set_order, NUMBER_TRIANING_SETS);

        for (int j = 0; j < NUMBER_TRIANING_SETS; j++)
        {
            int training_set_index = training_set_order[j];

            /* Firstly, we compute the hidden layer */
            for (int k = 0; k < NUMBER_HIDDEN_NODES; k++)
            {
                double activation = hidden_layer_bias[k];
                for (int l = 0; l < NUMBER_INPUTS; l++)
                {
                    activation += training_inputs[training_set_index][l] * hidden_layer_weights[l][k];
                }
                hidden_layer[k] = sigmoid(activation);
            }

            /* Secondly, we fill up the actual output array */
            for (int k = 0; k < NUMBER_OUTPUTS; k++)
            {
                double activation = output_layer_bias[k];
                for (int l = 0; l < NUMBER_HIDDEN_NODES; l++)
                {
                    activation += hidden_layer[l] * output_layer_weights[l][k];
                }
                output_layer[k] = sigmoid(activation);
            }

            printf(
                "Input: %f %f Output: %f    Expected Output: %f \n",
                training_inputs[training_set_index][0],
                training_inputs[training_set_index][1],
                output_layer[0],
                training_outputs[training_set_index][0]);

            /* Firstly, we compute the actual output error */
            double delta_output[NUMBER_OUTPUTS];
            for (int k = 0; k < NUMBER_OUTPUTS; k++)
            {
                double d_error = (training_outputs[training_set_index][k] - output_layer[k]);
                delta_output[k] = d_error * sigmoid_derivative(output_layer[k]);
            }

            /* Secondly, on compute the error of our training parameters */
            double delta_hidden_layer[NUMBER_HIDDEN_NODES];
            for (int k = 0; k < NUMBER_HIDDEN_NODES; k++)
            {
                double d_error_hidden = 0.0f;
                for (int l = 0; l < NUMBER_OUTPUTS; l++)
                {
                    d_error_hidden += delta_output[l] * output_layer_weights[k][l];
                }
                delta_hidden_layer[k] = d_error_hidden * sigmoid_derivative(hidden_layer[k]);
            }

            /* Thirdly, we fix, with the ouput actual error, the new output weight */
            for (int k = 0; k < NUMBER_OUTPUTS; k++)
            {
                output_layer_bias[k] += delta_output[k] * LEARNING_RATE;
                for (int l = 0; l < NUMBER_HIDDEN_NODES; l++)
                {
                    output_layer_weights[l][k] += hidden_layer[l] * delta_output[k] * LEARNING_RATE;
                }
            }

            /* And finally, we fix the weights of our parameters */
            for (int k = 0; k < NUMBER_HIDDEN_NODES; k++)
            {
                hidden_layer_bias[k] += delta_hidden_layer[k] * LEARNING_RATE;
                for (int l = 0; l < NUMBER_INPUTS; l++)
                {
                    hidden_layer_weights[l][k] += training_inputs[training_set_index][l] * delta_hidden_layer[k] * LEARNING_RATE;
                }
            }
        }
    }

    printf("Final Hidden Weights \n[ ");
    for (int i = 0; i < NUMBER_HIDDEN_NODES; i++)
    {
        printf("[ ");
        for (int j = 0; j < NUMBER_INPUTS; j++)
        {
            printf("%f ", hidden_layer_weights[j][i]);
        }
        printf("] ");
    }

    printf("]\n");
    printf("Final Hidden Biases \n[ ");
    for (int index = 0; index < NUMBER_HIDDEN_NODES; index++)
    {
        printf("%f ", hidden_layer_bias[index]);
    }

    printf("]\n");
    printf("Final Output Weights");
    for (int i = 0; i < NUMBER_OUTPUTS; i++)
    {
        printf("[ ");
        for (int j = 0; j < NUMBER_HIDDEN_NODES; j++)
        {
            printf("%f ", output_layer_weights[j][i]);
        }
        printf("]\n");
    }

    printf("Final Output Biases \n[ ");
    for (int i = 0; i < NUMBER_OUTPUTS; i++)
    {
        printf("%f ", output_layer_bias[i]);
    }

    printf("]\n");

    return 0;
}
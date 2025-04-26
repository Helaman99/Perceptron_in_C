// Time to practice more cool AI stuff!

/* # Notes

## Terminology
* Input Layer / Vector: An array of numbers, or 'input features'.
* Hidden Layer: An array of arrays, known as 'neurons'.
* Neuron: An array of numbers, known as 'weights', with a weight for each input feature.
* Output Layer: An array of neurons, with a neuron for every output possibility.
* Prediction: The output of the output layer, or the output of the AI.

## Process Summary
Multiply (dot product) the input layer by every neuron in the next hidden layer.
Activate every single product. Assemble those products into a new input layer.

## Things to remember
The number of weights in every neuron must match the number of input features in the
input layer.

With binary classification, typically only a single neuron is used along with the
Sigmoid activation function.

The activation function of the output layer and the activation used for the hidden
layers can be different.

In regards to activation functions
* ReLU is a usually a good starting point for an activation function, and is often used
for hidden layers.
* Sigmoid turns the input into a number between o and 1, hence its usefulness for
the output layer in binary classification.
* Softmax makes sure the output values all add to 1, hence its usefulness for
the output layer in multi-class classification.
* No activation function, also known as a linear activation function, is used for
regression where we want the prediction to be continuous values.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Layer.h"
#include "functions.h"

#define INPUT_FEATURES 5
#define LINE_LENGTH 1024

int main() {
    int input[INPUT_FEATURES] = {1, 2, 3, 4, 5};

    int layerCount = getLineCount("C:\\Git\\Perceptron_in_C\\network.csv", LINE_LENGTH);

    FILE* networkData = fopen("C:\\Git\\Perceptron_in_C\\network.csv", "r");
    if (!networkData) {
        perror("Error opening network file!");
        return EXIT_FAILURE;
    }

    char* currNum = NULL;
    int id = 0;
    int neuronCount = 0;
    int weightCount = 0;
    int** neurons = NULL;
    Layer* hiddenLayers = (Layer*)malloc(layerCount * sizeof(Layer));
    char line[LINE_LENGTH];
    printf("Processing input file...\n");
    while (fgets(line, sizeof(line), networkData)) {
        printf("Importing line %s\n", line);

        hiddenLayers[id].id = id + 1;
        printf("Creating layer with ID %d\n", hiddenLayers[id].id);

        neuronCount = atoi(strtok(line, ","));
        hiddenLayers[id].neuronCount = neuronCount;
        printf("Number of neurons: %d\n", neuronCount);

        weightCount = atoi(strtok(NULL, ","));
        hiddenLayers[id].weightCount = weightCount;
        printf("Number of weights per neuron: %d\n", weightCount);

        neurons = malloc(neuronCount * sizeof(int*));
        for (int i = 0; i < neuronCount; i++) {
            neurons[i] = malloc(weightCount * sizeof(int));
            for (int j = 0; j < weightCount; j++) {
                neurons[i][j] = atof(strtok(NULL, ","));
                printf("Adding weight: %d\n", neurons[i][j]);
            }
        }
        hiddenLayers[id].neurons = neurons;
        
        id++;
    }

    fclose(networkData);

    printf("Finished processing input file.\nNetwork contents:\n\n");
    for (int i = 0; i < layerCount; i++) {
        printLayer(hiddenLayers[i]);
    }
    printf("\n");

    int* inputLayer = input;
    int inputSize = INPUT_FEATURES;
    int* output = NULL;

    for (int i = 0; i < layerCount; i++) {
        output = multiplyLayers(inputLayer, inputSize, hiddenLayers[i]);
        if (i > 0) {
            free(inputLayer);
        }
        inputLayer = output;
        inputSize = hiddenLayers[i].neuronCount;
        freeLayer(hiddenLayers[i]);
    }

    printf("Output: { ");
    for (int i = 0; i < inputSize; i++) {
        printf("%d ", output[i]);
    }
    printf("}\n");
    free(output);

    return EXIT_SUCCESS;
}
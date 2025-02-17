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
#include "Layer.h"
#include "functions.h"

#define INPUT_FEATURES 5

int main() {
    int input[INPUT_FEATURES] = {1, 2, 3, 4, 5};

    int layerID = 1;
    int neuronCount = 2;
    int weightCount = 5;

    Layer layer1 = populateLayer(layerID, neuronCount, weightCount);

    layerID = 2;
    neuronCount = 2;
    weightCount = 2;

    Layer layer2 = populateLayer(layerID, neuronCount, weightCount);

    Layer hiddenLayers[2] = {
        layer1,
        layer2
    };

    int layerCount = sizeof(hiddenLayers) / sizeof(hiddenLayers[0]);
    int *inputVector = input;
    int inputSize = INPUT_FEATURES;
    int *output = NULL;

    for (int i = 0; i < layerCount; i++) {
        output = multiplyLayers(inputVector, inputSize, hiddenLayers[i]);
        if (i > 0) {
            free(inputVector);
        }
        inputVector = output;
        inputSize = hiddenLayers[i].neuronCount;
        freeLayer(hiddenLayers[i]);
    }

    printf("Output: { ");
    for (int i = 0; i < inputSize; i++) {
        printf("%d ", output[i]);
    }
    printf("}\n");
    free(output);

    return 0;
}
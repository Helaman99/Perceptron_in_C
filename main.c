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
    int inputVector[INPUT_FEATURES] = {1, 2, 3, 4, 5};

    int layerID = 1;
    int neuronCount = 2;
    int weightCount = 5;

    Layer layer1 = populateLayer(layerID, neuronCount, weightCount);
    printLayer(layer1);
    freeLayer(layer1);

    // Layer layer2 = {{
    //     {1, 2},
    //     {1, 2}
    // }, 2, 2};

    // Layer hiddenLayers[2] = {
    //     layer1,
    //     layer2
    // };

    // printf("Number of hidden layers: %d\n", (sizeof(hiddenLayers) / sizeof(hiddenLayers[0])));
    // printf("Number of neurons in layer 1: %d\n", hiddenLayers[0].neuronCount);
    // printf("Number of weights per neuron in layer 1: %d\n", hiddenLayers[0].weightCount);
    // printf("Number of neurons in layer 2: %d\n", hiddenLayers[1].neuronCount);
    // printf("Number of weights per neuron in layer 2: %d\n", hiddenLayers[1].weightCount);
    // printf("First weight in layer 1 neuron 1: %d\n", hiddenLayers[0].neurons[0][0]);

    //printf("%d\n", ((int (*)[5])hiddenLayers[0])[0][0]);
    // int layerCount = sizeof(hiddenLayers) / sizeof(hiddenLayers[0]);
    // // Pass sizes to the functions
    // int *output = inputVector;
    // for (int i = 0; i < layerCount; i++) {
    //     output = multiplyLayers(output, hiddenLayers[i]);

    //     // Free output after first iteration
    // }

    // int outputLength = sizeof(output) / sizeof(output[0]);
    // for (int i = 0; i < outputLength; i++) {
    //     printf("%d\n", output[i]);
    // }
    // free(output);

    return 0;
}
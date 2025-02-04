// Time to practice more cool AI stuff!

/* # Notes

## Terminology
* Input Neuron: An array of numbers, or 'input features'.
* Hidden Neuron: An array of arrays, known as 'neurons'.
* Neuron: An array of numbers, known as 'weights', with a weight for each input feature.
* Output Neuron: An array of neurons, with a neuron for every output possibility.
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
#include "functions.h"

int main() {
    int inputLayer[] = {1, 2, 3, 4, 5};

    int layer1[2][5] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}
    };

    int layer2[2][2] = {
        {1, 2},
        {1, 2}
    };

    int *hiddenLayers[2] = {
        (int *)layer1,
        (int *)layer2
    };

    //printf("%d\n", ((int (*)[5])hiddenLayers[0])[0][0]);

    int neurons = sizeof(layer1) / sizeof(layer1[0]);
    int *output = (int*)malloc(neurons * sizeof(int));

    for (int i = 0; i < neurons; i++) {
        output[i] = dot(inputLayer, layer1[i]);
        printf("%d\n", output[i]);
    }
    free(output);

    return 0;
}
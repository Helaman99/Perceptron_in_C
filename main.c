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

#define LINE_MAX_LENGTH 4096

int main(int argc, char* argv[]) {

    if (argc > 1) {
        if (strcmp(argv[1], "--test") == 0) {
            double input[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
            char* filePath = "new-network.csv";

            int layerCount = getLineCount(filePath, LINE_MAX_LENGTH);
            Layer* testLayers = importNetwork(filePath, layerCount, LINE_MAX_LENGTH);

            int inputSize = sizeof(input) / sizeof(input[0]);
            predict(input, inputSize, layerCount, testLayers);
        }
        else if (strcmp(argv[1], "--init-network") == 0) {
            initNetwork(LINE_MAX_LENGTH, argv[2]);
        }
        else {
            printHelp();
        }
    }
    else {
        printHelp();
    }

    return EXIT_SUCCESS;
}
// Time to practice more cool AI stuff!

/* # Notes

## Terminology
* Input Layer: An array of numbers, or 'input features'.
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

int log(const char * msg) {
    printf("%s", msg);
    return 0;
}

int dot(const int *arr1, const int *arr2, int size) {
    int result = 0;

    for (int i = 0; i < size; i++) {
        result += arr1[i] * arr2[i];
    }

    return result;
}

int main() {
    int inputLayer[5] = {1, 2, 3, 4, 5};

    int result = dot(data);

    printf("The result: %d\n", result);
    return 0;
}
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int dot(const int *arr1, const int *arr2, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += arr1[i] * arr2[i];
    }
    return result;
}

int* multiplyLayers(const int* inputVector, int inputSize, const Layer hiddenLayer) {
    int *output = (int*)malloc(hiddenLayer.neuronCount * sizeof(int));
    for (int i = 0; i < hiddenLayer.neuronCount; i++) {
        output[i] = dot(inputVector, hiddenLayer.neurons[i], inputSize);
    }
    return output;
}

#endif
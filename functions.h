#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int dot(const int *arr1, const int *arr2) {
    int result = 0;
    int size = sizeof(arr1) / sizeof(arr1[0]);

    for (int i = 0; i < size; i++) {
        result += arr1[i] * arr2[i];
    }

    return result;
}

int* multiplyLayers(const int* inputVector, const int* hiddenLayer) {
    int neurons = sizeof(hiddenLayer) / sizeof(hiddenLayer[0]);
    int *output = (int*)malloc(neurons * sizeof(int));

    for (int i = 0; i < neurons; i++) {
        output[i] = dot(inputVector, hiddenLayer[i]);
    }

    free(inputVector);
    return output;
}

#endif
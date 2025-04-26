#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

int getLineCount(const char* fileName, int maxLineLength) {
    FILE* file = fopen(fileName, "r");
    if (!file) {
        perror("Error opening network file!\n");
        return EXIT_FAILURE;
    }

    int lineCount = 0;
    char* line = calloc(maxLineLength, sizeof(char));
    while (fgets(line, maxLineLength, file)) {
        lineCount++;
    }
    free(line);
    fclose(file);

    return lineCount;
}

int dot(const int* arr1, const int* arr2, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += arr1[i] * arr2[i];
    }
    return result;
}

int* multiplyLayers(const int* inputLayer, int inputSize, const Layer hiddenLayer) {
    int* output = (int*)malloc(hiddenLayer.neuronCount * sizeof(int));
    for (int i = 0; i < hiddenLayer.neuronCount; i++) {
        output[i] = dot(inputLayer, hiddenLayer.neurons[i], inputSize);
    }
    return output;
}

#endif
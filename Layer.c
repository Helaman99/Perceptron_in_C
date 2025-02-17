#include <stdio.h>
#include <stdlib.h>
#include "Layer.h"

Layer populateLayer(int id, int neuronCount, int weightCount) {
    int **neurons = malloc(neuronCount * sizeof(int *));
    for (int i = 0; i < neuronCount; i++) {
        neurons[i] = malloc(weightCount * sizeof(int));
    }

    for (int i = 0; i < neuronCount; i++) {
        for (int j = 0; j < weightCount; j++) {
            neurons[i][j] = j + 1;
        }
    }

    Layer layer = {id, neurons, neuronCount, weightCount};

    return layer;
}

void printLayer(Layer layer) {
    printf("Contents of layer ID %d:\n", layer.id);
    printf("Neurons: %d | Weights per neuron: %d\n", layer.neuronCount, layer.weightCount);
    for (int neuron = 0; neuron < layer.neuronCount; neuron++) {
        printf("Neuron %d: {", neuron);
        for (int weight = 0; weight < layer.weightCount; weight++) {
            printf(" %d", layer.neurons[neuron][weight]);
        }
        printf(" }\n");
    }
}

void freeLayer(Layer layer) {
    printf("Freeing contents of layer ID %d... ", layer.id);
    for (int i = 0; i < layer.neuronCount; i++) {
        free(layer.neurons[i]);
    }
    free(layer.neurons);
    printf(" contents freed!\n");
}
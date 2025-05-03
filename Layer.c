#include <stdio.h>
#include <stdlib.h>
#include "Layer.h"

void printLayer(Layer layer) {
    printf("Contents of layer ID %d:\n", layer.id);
    printf("Neurons: %d | Weights per neuron: %d\n", layer.neuronCount, layer.weightCount);
    for (int neuron = 0; neuron < layer.neuronCount; neuron++) {
        printf("Neuron %d: {", neuron + 1);
        for (int weight = 0; weight < layer.weightCount; weight++) {
            printf(" %.6f", layer.neurons[neuron][weight]);
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
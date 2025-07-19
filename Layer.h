#ifndef LAYER_H
#define LAYER_H

typedef struct {
    int id;
    int neuronCount;
    int weightCount;
    double** neurons;
    double* biases;
} Layer;

Layer populateLayer(int id, int neuronCount, int weightCount);
void printLayer(Layer layer);
void freeLayer(Layer layer);

#endif
#ifndef LAYER_H
#define LAYER_H

typedef struct {
    int id;
    int ** neurons;
    int neuronCount;
    int weightCount;
} Layer;

Layer populateLayer(int id, int neuronCount, int weightCount);
void printLayer(Layer layer);
void freeLayer(Layer layer);

#endif
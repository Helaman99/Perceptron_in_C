#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

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

// Creates new CSV file that houses a neural network with randomized weights
void initNetwork(int maxLineLength, char* filePath) {
    FILE* input = fopen(filePath, "r");
    if (!input) {
        perror("Error opening file!");
        return;
    }

    FILE* outputFile = fopen("new-network.csv", "w");
    srand(time(NULL));

    int neuronCount, weightCount, totalWeights;
    char* line = calloc(maxLineLength, sizeof(char));

    printf("Processing input file...\n");

    while (fgets(line, maxLineLength, input)) {
        printf("Importing line %s\n", line);

        neuronCount = atoi(strtok(line, ","));
        weightCount = atoi(strtok(NULL, ","));
        totalWeights = neuronCount * weightCount;

        printf("Number of neurons: %d\n", neuronCount);
        printf("Number of weights per neuron: %d\n", weightCount);

        char* weights = malloc(totalWeights * 10);
        weights[0] = '\0';

        for (int i = 0; i < totalWeights; i++) {
            char temp[10];
            snprintf(temp, sizeof(temp), ",%.2f", ((double)rand() / RAND_MAX));
            strcat(weights, temp);
        }

        fprintf(outputFile, "%d,%d%s\n", neuronCount, weightCount, weights);
        free(weights);
    }

    fclose(input);
    fclose(outputFile);
    free(line);
}

// Initializes the neural network based on the contents of a CSV file
Layer* importNetwork(char* filePath, int layerCount, int maxLineLength) {
    FILE* networkData = fopen(filePath, "r");
    if (!networkData) {
        perror("Error opening network file!/n");
        exit(EXIT_FAILURE);
    }

    int id = 0, neuronCount = 0, weightCount = 0;
    double** neurons = NULL;
    Layer* hiddenLayers = (Layer*)malloc(layerCount * sizeof(Layer));
    char* line = calloc(maxLineLength, sizeof(char));

    printf("Processing input file...\n");

    while (fgets(line, maxLineLength, networkData)) {
        //printf("Importing line: %s\n", line);

        hiddenLayers[id].id = id + 1;
        neuronCount = atoi(strtok(line, ","));
        hiddenLayers[id].neuronCount = neuronCount;
        weightCount = atoi(strtok(NULL, ","));
        hiddenLayers[id].weightCount = weightCount;

        printf("Initializing layer with ID %d, %d neurons, and %d weights per nueron...\n", hiddenLayers[id].id, neuronCount,weightCount);

        neurons = malloc(neuronCount * sizeof(double*));
        for (int i = 0; i < neuronCount; i++) {
            neurons[i] = malloc(weightCount * sizeof(double));

            for (int j = 0; j < weightCount; j++) {
                char* token = strtok(NULL, ",");
                if (token) {
                    neurons[i][j] = atof(token);
                } else {
                    printf("Warning: Missing weight value!\n");
                }
                //printf("Adding weight: %.6f\n", neurons[i][j]);
            }
        }
        hiddenLayers[id].neurons = neurons;
        id++;
    }

    fclose(networkData);
    free(line);

    printf("Finished processing input file.\n");
    return hiddenLayers;
}

// Takes two vectors and multiplies them together
double dot(const double* arr1, const double* arr2, int size) {
    double result = 0.0;
    for (int i = 0; i < size; i++) {
        result += arr1[i] * arr2[i];
    }
    return result;
}

// Takes two layers and multiples them together
double* multiplyLayers(const double* inputLayer, int inputSize, const Layer hiddenLayer) {
    double* output = malloc(hiddenLayer.neuronCount * sizeof(double));
    for (int i = 0; i < hiddenLayer.neuronCount; i++) {
        output[i] = dot(inputLayer, hiddenLayer.neurons[i], inputSize);
    }
    return output;
}

void predict(double* input, int inputSize, int layerCount, Layer* hiddenLayers) {
    double* inputLayer = input;
    double* output;

    for (int i = 0; i < layerCount; i++) {
        if (inputSize != hiddenLayers[i].weightCount) {
            perror("Input weight count did not match hidden layer weight count.");
            exit(EXIT_FAILURE);
        }

        output = multiplyLayers(inputLayer, inputSize, hiddenLayers[i]);
        if (i > 0) { free(inputLayer); }

        inputLayer = output;
        inputSize = hiddenLayers[i].neuronCount;

        freeLayer(hiddenLayers[i]);
    }

    printf("\nFinal output: { ");
    for (int i = 0; i < inputSize; i++) { printf("%.6f ", output[i]); }
    printf("}\n");

    free(output);
}

void printHelp() {
    printf("Welcome to Perceptron in C's Help Page!\n");
    printf("This is a program designed to let you build and use a neural network with ease.\n\nThe possible arguments that can be used are as follows:\n\n");

    printf("--train [network_file].csv [training_set].csv               This will train your neural network with the specified training data set.\n");
    printf("--predict [network_file].csv [input_layer].csv              This will use your neural network to make a prediction based on the input layer.\n");
    printf("--init-network [network_structure].csv                      This will create a new CSV file with the contents of a randomly initialized neural network based on the structure provided in the specified file.\n");
    printf("                                                            The CSV file that has the structure of your desired network should follow the following format:\n");
    printf("                                                            [number_of_neurons],[number_of_weights_per_neuron] <-- Repeat this on every line for every layer.\n");
}

#endif
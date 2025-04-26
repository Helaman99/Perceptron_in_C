# Perceptron_in_C
To deepen my understanding of AI and of the C language, I am building another Perceptron in C.

At this current stage in it's development, the input vector is defined in the code and must be changed accordingly.

However, the neural network that you wish to use will be kept in the `network.csv` file, and should be structured as follows:

[number of neurons for this layer],[number of weights per neuron],[first weight for the first neuron],[second weight for second neuron]...

For example:

2,5,1,2,3,4,5,5,4,3,2,1

This line specifies that this layer will contain 2 neurons, and each neuron will have 5 weights. The weights for the first neuron are 1, 2, 3, 4, and 5. The weights for the second neuron are then specified to be 5, 4, 3, 2, and 1.

The functionality for training the model and saving the values of the new weights are yet to be added, but are on the way.
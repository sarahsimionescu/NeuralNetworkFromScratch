#include <iostream>
#include "dataset.h"
#include "network.h"
#include "vectors.h"
#include <cmath>
#include "cpgplot.h"
#include <string.h>
#include <iomanip>

using namespace std;



int main()
{
    Dataset validationData = Dataset("/home/simiones/project/t10k-images.idx3-ubyte", "/home/simiones/project/t10k-labels.idx1-ubyte", 0, 9);
    Dataset trainingData = Dataset("/home/simiones/project/train-images.idx3-ubyte", "/home/simiones/project/train-labels.idx1-ubyte", 0, 9);
    Network network = Network(784, 10, 10);
    int epochs = 10;
    int batch_size = 10000;
    int total_iterations = epochs * trainingData.size / batch_size;
    float* xvalues = new float[total_iterations];
    float* training_data_results = new float[total_iterations];
    float* validation_data_results = new float[total_iterations];
    for (int i = 0; i < total_iterations; i++)
    {
        xvalues[i] = i;
    }
    network.train(trainingData, validationData, 1, epochs, batch_size, training_data_results, validation_data_results);
    // Open a plot window
    if (!cpgopen("/XWINDOW"))
        return 1;
    // Set up axis
    cpgenv(0, total_iterations - 1, 0, 1, 0, 1);
    // Label axes
    cpglab("epochs and batches", "accuracy", "");
    // Change plot colour to blue
    cpgsci(5);
    // Plot the original curve
    cpgline(total_iterations, xvalues, training_data_results);
    // Change plot colour to green
    cpgsci(2);
    // Plot the original curve
    cpgline(total_iterations, xvalues, validation_data_results);

    // Pause and then close plot window
    cpgclos();

    return 0;

}
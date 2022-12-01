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
    Dataset validationData = Dataset("path-to/t10k-images.idx3-ubyte", "path-to/t10k-labels.idx1-ubyte", 0, 9); // enter the path to each respective file
    Dataset trainingData = Dataset("path-to/train-images.idx3-ubyte", "path-to/train-labels.idx1-ubyte", 0, 9); // enter the path to each respective file
    Network network = Network(784, 10, 10);
    int epochs = 10;
    int batch_size = 10000;
    float* xvalues = new float[epochs];
    float* training_data_results = new float[epochs];
    float* validation_data_results = new float[epochs];
    for (int i = 0; i < epochs; i++)
    {
        xvalues[i] = i;
    }
    network.train(trainingData, validationData, 1, epochs, batch_size, training_data_results, validation_data_results);
    // Open a plot window
    if (!cpgopen("/XWINDOW"))
        return 1;
    // Set up axis
    cpgenv(0, epochs - 1, 0, 1, 0, 1);
    // Label axes
    cpglab("epochs", "accuracy", "");
    // Change plot colour to blue
    cpgsci(5);
    // Plot the original curve
    cpgline(epochs, xvalues, training_data_results);
    // Change plot colour to green
    cpgsci(2);
    // Plot the original curve
    cpgline(epochs, xvalues, validation_data_results);

    // Pause and then close plot window
    cpgclos();

    return 0;

}

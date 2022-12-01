#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "dataset.h"
#include "relulayer.h"
#include "softmaxlayer.h"
#include "denselayer.h"

using namespace std;

class Network {
public:
    DenseLayer h1;
    ReLULayer a1;
    DenseLayer h2;
    SoftMaxLayer a2;
    int input_size;
    int hidden_size;
    int output_size;
    Network(int input_size, int hidden_size, int output_size);

    void train(const Dataset& training_data, const Dataset& validation_data, long double learning_rate, int epochs, int batch_size, float* training_data_results, float* validation_data_results);

    vector<long double> forwards(const vector<long double>& input);

};

#endif
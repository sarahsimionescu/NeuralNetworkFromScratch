#ifndef DENSELAYER_H
#define DENSELAYER_H

#include <vector>
#include "layer.h"

using namespace std;

class DenseLayer :public Layer {
public:
    vector<vector<long double> > weights;
    vector<long double> biases;
    DenseLayer();
    DenseLayer(int input_size, int output_size);
    void resetBiases();
    void resetWeights();
    vector<long double> forwards(const vector<long double>& input);
};

#endif
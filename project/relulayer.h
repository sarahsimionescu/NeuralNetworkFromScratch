#ifndef RELULAYER_H
#define RELULAYER_H

#include <vector>
#include "layer.h"

using namespace std;

class ReLULayer :public Layer {
public:
    ReLULayer();
    ReLULayer(int input_size, int output_size);
    long double function(long double x);
    long double derivative(long double x);
    vector<long double> forwards(const vector<long double>& input);
    vector<vector<long double> > backwards(const vector<vector<long double> >& input, int batch_size);
};

#endif
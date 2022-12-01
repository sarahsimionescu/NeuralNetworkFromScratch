#ifndef SOFTMAXLAYER_H
#define SOFTMAXLAYER_H

#include <vector>
#include "layer.h"

using namespace std;

class SoftMaxLayer :public Layer {
public:
    SoftMaxLayer();
    SoftMaxLayer(int input_size, int output_size);
    vector<long double> forwards(const vector<long double>& input);
};

#endif
#include <vector>
#include "layer.h"
#include "softmaxlayer.h"
#include <cmath>

SoftMaxLayer::SoftMaxLayer():Layer() {}

SoftMaxLayer::SoftMaxLayer(int input_size, int output_size):Layer(input_size,output_size) {}

vector<long double> SoftMaxLayer::forwards(const vector<long double>& input) {
    vector<long double> output = vector<long double>(this->output_size);
    long double sum = 0;
    for(int i =0; i < this->input_size; i++)
    {
        sum += exp(input[i]);
    }
    for (int i =0 ; i < this->output_size; i++)
    {
        output[i] = exp(input[i])/sum;
    }
    return output;
}

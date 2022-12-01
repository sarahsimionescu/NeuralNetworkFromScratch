#ifndef LAYER_H
#define LAYER_H

#include <vector>

using namespace std;

class Layer {
public:
    int input_size;
    int output_size;
    Layer(int input_size, int output_size);
    Layer();
    virtual vector<long double> forwards(const vector<long double>& input) = 0;
};

#endif
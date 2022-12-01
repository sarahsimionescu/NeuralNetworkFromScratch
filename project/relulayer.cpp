#include <vector>
#include "layer.h"
#include "relulayer.h"

ReLULayer::ReLULayer():Layer() {}

ReLULayer::ReLULayer(int input_size, int output_size):Layer(input_size,output_size) {}

long double ReLULayer::function(long double x){
    if(x > 0){
        return x;
    }else{
        return 0;
    }
}

long double ReLULayer::derivative(long double x){
    if(x > 0){
        return 1;
    }else{
        return 0;
    }
}


vector<long double> ReLULayer::forwards(const vector<long double>& input) {
    vector<long double> output = vector<long double>(this->output_size);
    for(int i =0; i < output_size; i++)
    {
        output[i] = this->function(input[i]);
    }
    return output;
}


vector<vector<long double> > ReLULayer::backwards(const vector<vector<long double> >& input, int batch_size) {
    vector<vector<long double> > output = vector<vector<long double> >(batch_size, vector<long double>(this->input_size));
    for(int i =0; i < batch_size; i++)
    {
        for(int j = 0; j < this->input_size; j++)
        {
            output[i][j] = this->derivative(input[i][j]);
        }
    }
    return output;
}
#include <vector>
#include "layer.h"
#include "denselayer.h"
#include <time.h>
#include <cstdlib>


DenseLayer::DenseLayer():Layer() {}

DenseLayer::DenseLayer(int input_size, int output_size):Layer(input_size,output_size) {
    resetBiases();
    resetWeights();
}


void DenseLayer::resetBiases() {
    srand((unsigned)time(NULL));
    this->biases = vector<long double>(this->output_size);
    for(int i =0; i < this->biases.size(); i++)
    {
        this->biases[i] = ((long double)rand() / RAND_MAX)-0.5;
    }
}


void DenseLayer::resetWeights() {
    srand((unsigned)time(NULL));
        
    this->weights = vector<vector<long double> >(this->output_size, vector<long double>(this->input_size));
    for(int i =0; i < this->weights.size(); i++)
    {
        for(int j=0; j < this->weights[0].size(); j++){
            this->weights[i][j] = ((long double)rand() / RAND_MAX)-0.5;
        }
    }
}

vector<long double> DenseLayer::forwards(const vector<long double>& input)
{
    vector<long double> output = vector<long double>(this->output_size);
    for(int i = 0; i < this->output_size; i++)
    {
        long double sum = this->biases[i];
        for(int j = 0; j < this->input_size; j++)
        {
            sum+= input[j]*weights[i][j];
        }
        output[i] = sum;
    }
    return output;
}

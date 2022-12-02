#include <vector>
#include <iostream>
#include "network.h"
#include "vectors.h"
#include "relulayer.h"
#include "softmaxlayer.h"
#include "denselayer.h"


Network::Network(int input_size, int hidden_size, int output_size) {
    this->input_size = input_size;
    this->hidden_size = hidden_size;
    this->output_size = output_size;
    cout << "Initializing network with input layer size " << input_size << ", hidden layer size " << hidden_size << ", and output layer size " << output_size << "...\n";
    h1 = DenseLayer(input_size, hidden_size);
    a1 = ReLULayer(hidden_size, hidden_size);
    h2 = DenseLayer(hidden_size, output_size);
    a2 = SoftMaxLayer(output_size, output_size);
}


void Network::train(const Dataset& training_data, const Dataset& validation_data, long double learning_rate, int epochs, int batch_size, float* training_data_results, float* validation_data_results) {
    for (int e = 0; e < epochs; e++)
    {
        long double training_data_accuracy = 0;
        long double validation_data_accuracy = 0;
        cout << "Beginning epoch " << e << "\n";
        for (int b = 0; b < training_data.size; b += batch_size) {
            cout << "Running training batch " << b << " to " << b + batch_size - 1 << "\n";
            cout << "Initializing vectors for storing layer outputs...\n";
            vector<vector<long double> > inputs = getcolumns(training_data.inputs, b, b + batch_size - 1);
            vector<vector<long double> > outputs = getcolumns(training_data.outputs, b, b + batch_size - 1);
            vector<vector<long double> > h1_outputs = vector<vector<long double> >(batch_size, vector<long double>(this->h1.output_size));
            vector<vector<long double> > a1_outputs = vector<vector<long double> >(batch_size, vector<long double>(this->a1.output_size));
            vector<vector<long double> > h2_outputs = vector<vector<long double> >(batch_size, vector<long double>(this->h2.output_size));
            vector<vector<long double> > a2_outputs = vector<vector<long double> >(batch_size, vector<long double>(this->a2.output_size));
            cout << "Forwards propigation...\n";
            for (int i = 0; i < batch_size; i++) {
                h1_outputs[i] = this->h1.forwards(inputs[i]);
                a1_outputs[i] = this->a1.forwards(h1_outputs[i]);
                h2_outputs[i] = this->h2.forwards(a1_outputs[i]);
                a2_outputs[i] = this->a2.forwards(h2_outputs[i]);
            }
            cout << "Current accuracy on training data...\n";
            training_data_accuracy = 0;
            for (int i = 0; i < batch_size; i++)
            {
                if (max_index(a2_outputs[i]) == training_data.output_numbers[b + i])
                {
                    training_data_accuracy += 1;
                }
            }
            training_data_accuracy = training_data_accuracy / (long double)batch_size;
            cout << "Accuracy: " << training_data_accuracy << "\n";
            cout << "Current accuracy on validation data...\n";
            validation_data_accuracy = 0;
            for (int i = 0; i < validation_data.size; i++)
            {
                if (max_index(this->forwards(validation_data.inputs[i])) == validation_data.output_numbers[i])
                {
                    validation_data_accuracy += 1;
                }
            }
            validation_data_accuracy = validation_data_accuracy / (long double)batch_size;
            cout << "Accuracy: " << validation_data_accuracy << "\n";
            training_data_results[(e * training_data.size + b) / batch_size] = (float)training_data_accuracy;
            validation_data_results[(e * training_data.size + b) / batch_size] = (float)validation_data_accuracy;
            cout << "Backwards propigation...\n";
            vector<vector<long double> > delta_2 = sub(a2_outputs, outputs);
            vector<vector<long double> > delta_weights2 = scale(dot_transpose1(delta_2, a1_outputs), 1 / (long double)batch_size);
            vector<long double> delta_biases2 = average_column(delta_2);
            vector<vector<long double> > a1_backwards = vector<vector<long double> >(batch_size);
            vector<vector<long double> > delta_1 = mult(dot(delta_2, h2.weights), a1.backwards(h1_outputs, batch_size));
            vector<vector<long double> > delta_weights1 = scale(dot_transpose1(delta_1, inputs), 1 / (long double)batch_size);
            vector<long double> delta_biases1 = average_column(delta_1);
            cout << "Applying changes...\n";
            h2.weights = sub(h2.weights, scale(delta_weights2, learning_rate));
            h2.biases = sub(h2.biases, scale(delta_biases2, learning_rate));
            h1.weights = sub(h1.weights, scale(delta_weights1, learning_rate));
            h1.biases = sub(h1.biases, scale(delta_biases1, learning_rate));
        }

    }
}

vector<long double> Network::forwards(const vector<long double>& input)
{
    return a2.forwards(h2.forwards(a1.forwards(h1.forwards(input))));
}



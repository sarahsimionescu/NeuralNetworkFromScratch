#include <fstream>
#include <cstdlib>
#include <vector>
#include <iostream>
#include "dataset.h"

using namespace std;


int Dataset::reverseInt(int i)
{
    unsigned char c1, c2, c3, c4;

    c1 = i & 255;
    c2 = (i >> 8) & 255;
    c3 = (i >> 16) & 255;
    c4 = (i >> 24) & 255;

    return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
}

void Dataset::read_mnist_images(const char* path)
{
    ifstream file(path);
    cout << "Opening " << path << "...\n";
    if (file.is_open())
    {
        int magic_number, number_of_columns, number_of_rows, number_of_images;
        file.read((char*)&magic_number, sizeof(magic_number));
        magic_number = this->reverseInt(magic_number);
        cout << "Magic number: " << magic_number << "\n";
        file.read((char*)&number_of_images, sizeof(number_of_images));
        number_of_images = reverseInt(number_of_images);
        cout << "Number of images: " << number_of_images << "\n";
        file.read((char*)&number_of_rows, sizeof(number_of_rows));
        number_of_rows = reverseInt(number_of_rows);
        cout << "Number of rows: " << number_of_rows << "\n";
        this->image_num_rows = number_of_rows;
        cout << "Updated image number of rows to: " << this->image_num_rows << "\n";
        file.read((char*)&number_of_columns, sizeof(number_of_columns));
        number_of_columns = reverseInt(number_of_columns);
        cout << "Number of columns: " << number_of_columns << "\n";
        this->image_num_col = number_of_columns;
        cout << "Updated image number of columns to: " << this->image_num_col << "\n";
        cout << "Initializing Inputs Vector...\n";
        this->inputs = vector<vector<long double> >(number_of_images, vector<long double>(number_of_columns * number_of_rows));
        cout << "Loading images...\n";
        for (int i = 0; i < number_of_images; i++)
        {
            for (int j = 0; j < number_of_rows * number_of_columns; j++)
            {
                unsigned char temp = 0;
                file.read((char*)&temp, sizeof(temp));
                this->inputs[i][j] = ((long double)temp) / 255;
            }
        }
        cout << "Success!\n";
        this->size = number_of_images;
        cout << "Updated dataset size to: " << this->size << "\n";
    }
    else {
        cout << "Error: file " << path << " could not open!\n\n";
    }
}

void Dataset::read_mnist_labels(const char* path, int label_range_min, int label_range_max)
{
    ifstream file(path);
    cout << "Opening " << path << "...\n";
    if (file.is_open())
    {
        int magic_number, number_of_labels;
        file.read((char*)&magic_number, sizeof(magic_number));
        magic_number = this->reverseInt(magic_number);
        cout << "Magic number: " << magic_number << "\n";
        file.read((char*)&number_of_labels, sizeof(number_of_labels));
        number_of_labels = reverseInt(number_of_labels);
        cout << "Number of labels: " << number_of_labels << "\n";
        cout << "Loading labels...\n";
        for (int i = 0; i < number_of_labels; i++)
        {
            unsigned char temp = 0;
            file.read((char*)&temp, sizeof(temp));
            outputs.push_back(hot_encode((unsigned int)temp, label_range_min, label_range_max));
            output_numbers.push_back((int)(unsigned int)temp);
        }
        cout << "Success!\n";
        this->size = number_of_labels;
        cout << "Updated dataset size to: " << this->size << "\n";
    }
    else {
        cout << "Error: file " << path << " could not open!\n\n";
    }

}

void Dataset::print(int k) {
    cout << "\n";

    for (int i = 0; i < this->image_num_rows; i++) {
        cout << "\n";
        for (int j = 0; j < this->image_num_col; j++)
        {
            long double pixel = this->inputs[k][i * image_num_rows + j];
            if (pixel > 0.7) {
                cout << "#";
            }
            else if (pixel > 0.5) {
                cout << "+";
            }
            else if (pixel > 0.2) {
                cout << "-";
            }
            else {
                cout << " ";
            }
        }
    }
    cout << "\n ------- ";
    cout << this->output_numbers[k];
    cout << " ------- \n";
}

void Dataset::printAll() {
    for (int k = 0; k < this->size; k++)
    {
        this->print(k);
    }
}

vector<long double> Dataset::hot_encode(unsigned int input, int label_range_min, int label_range_max)
{
    vector<long double> output;
    for (int i = label_range_min; i <= label_range_max; i++)
    {
        if (input == i) {
            output.push_back(1);
        }
        else {
            output.push_back(0);
        }
    }
    return output;
}

Dataset::Dataset(const char* image_path, const char* label_path, int label_range_min, int label_range_max) {
    this->read_mnist_images(image_path);
    this->read_mnist_labels(label_path, label_range_min, label_range_max);
}

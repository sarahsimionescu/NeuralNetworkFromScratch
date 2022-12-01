#ifndef DATASET_H
#define DATASET_H

#include <vector>

using namespace std;

class Dataset {
public:
    Dataset(const char* image_path, const char* label_path, int label_range_min, int label_range_max);
    int size;
    int image_num_rows;
    int image_num_col;
    vector<vector<long double> > inputs;
    vector<vector<long double> > outputs;
    vector<int> output_numbers;
    int reverseInt(int i);
    void read_mnist_images(const char* path);
    void read_mnist_labels(const char* path,int label_range_min, int label_range_max);
    vector<long double> hot_encode(unsigned int input, int label_range_min, int label_range_max);
    void print(int k);
    void printAll();
};

#endif
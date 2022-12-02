# NeuralNetworkFromScratch
I decided to create a simple back propagation neural network from scratch in C++ as part of my final project for my Scientific Computing course (DATASCI 2G03).

## Instructions for Use
**Read the project proposal to learn about the model and how it works!**
  1. Unzip the training data and training labels
  2. Enter the paths to each respective dataset file in `demo.cpp`
  3. Run `make`
  4. Run `./demo` and the output to the terminal will describe the program as it runs.

## Environment Information
- Running on CentOS Linux 7 (Core)
- gcc (GCC) version 4.8.5 (Red Hat 4.8.5-44)

## Sample Output
```
Opening path-to/t10k-images.idx3-ubyte...
Magic number: 2051
Number of images: 10000
Number of rows: 28
Updated image number of rows to: 28
Number of columns: 28
Updated image number of columns to: 28
Initializing Inputs Vector...
Loading images...
Success!
Updated dataset size to: 10000
Opening path-to/t10k-labels.idx1-ubyte...
Magic number: 2049
Number of labels: 10000
Loading labels...
Success!
Updated dataset size to: 10000
Opening path-to/train-images.idx3-ubyte...
Magic number: 2051
Number of images: 60000
Number of rows: 28
Updated image number of rows to: 28
Number of columns: 28
Updated image number of columns to: 28
Initializing Inputs Vector...
Loading images...
Success!
Updated dataset size to: 60000
Opening path-to/project/train-labels.idx1-ubyte...
Magic number: 2049
Number of labels: 60000
Loading labels...
Success!
Updated dataset size to: 60000
Initializing network with input layer size 784, hidden layer size 10, and output layer size 10...
Beginning epoch 0
Running training batch 0 to 9999
Initializing vectors for storing layer outputs...
Forwards propigation...
Current accuracy on training data...
Accuracy: 0.0507
Current accuracy on validation data...
Accuracy: 0.0539
Backwards propigation...
Applying changes...
...(continued for 10 epochs)...
Running training batch 50000 to 59999
Initializing vectors for storing layer outputs...
Forwards propigation...
Current accuracy on training data...
Accuracy: 0.7744
Current accuracy on validation data...
Accuracy: 0.7606
Backwards propigation...
Applying changes...
```

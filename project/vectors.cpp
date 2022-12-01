#include <fstream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <cmath>
#include <iostream>

using namespace std;

void assert(bool check, const char* error_message) {
    if (check == 0) {
        cout << "Error: " << error_message << "\n";
    }
}

int max_index(const vector<long double>& input) {
    assert(!input.empty(), "cannot be empty for print for max_index");
    long double max = -INFINITY;
    int max_index = -1;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] > max) {
            max = input[i];
            max_index = i;
        }
    }
    return max_index;
}

void print_size(const vector<vector<long double> >& input) {
    cout << input.size() << ", " << input[0].size() << "\n";
}

void print_size(const vector<long double>& input) {
    cout << input.size() << "\n";
}

void print(const vector<vector<long double> >& input) {
    assert(!input.empty(), "cannot be empty for print");
    for (int j = 0; j < input[0].size(); j++)
    {
        for (int i = 0; i < input.size(); i++)
        {
            cout << input[i][j] << " ";
        }
        cout << "\n";
    }
}

void print(const vector<long double>& input) {
    assert(!input.empty(), "cannot be empty for print");
    cout << "Single column vector:";
    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    cout << "\n";
}


void print_visual(const vector<long double>& input, int row_size) {
    assert(!input.empty(), "cannot be empty for print");
    cout << "Single column vector interpreted as an image:";
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < input.size() / row_size; j++)
        {
            long double pixel = input[i * row_size + j];
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
        cout << "\n";
    }
    cout << "\n";
}

vector<vector<long double> > sub(const vector<vector<long double> >& input1, const vector<vector<long double> >& input2) {
    assert(input1.size() == input2.size() && input1[0].size() == input2[0].size() && !input1.empty(), "size mismatch for sub");
    vector<vector<long double> > output = vector<vector<long double> >(input1.size(), vector<long double>(input1[0].size()));
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[0].size(); j++)
        {
            output[i][j] = input1[i][j] - input2[i][j];
        }
    }
    return output;
}

vector<long double> sub(const vector<long double>& input1, const vector<long double>& input2) {
    assert(input1.size() == input2.size() && !input1.empty(), "size mismatch for sub");
    vector<long double> output = vector<long double>(input1.size());
    for (int i = 0; i < output.size(); i++)
    {
        output[i] = input1[i] - input2[i];
    }
    return output;
}

vector<vector<long double> > add(const vector<vector<long double> >& input1, const vector<vector<long double> >& input2) {
    assert(input1.size() == input2.size() && input1[0].size() == input2[0].size() && !input1.empty(), "size mismatch for add");
    vector<vector<long double> > output = vector<vector<long double> >(input1.size(), vector<long double>(input1[0].size()));
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[0].size(); j++)
        {
            output[i][j] = input1[i][j] + input2[i][j];
        }
    }
    return output;
}

vector<vector<long double> > dot(const vector<vector<long double>  >& inputnxm, const vector<vector<long double> >& inputmxk) {
    assert(inputnxm[0].size() == inputmxk.size() && !inputnxm.empty(), "size mismatch for dot");
    vector<vector<long double> > output = vector<vector<long double> >(inputnxm.size(), vector<long double>(inputmxk[0].size()));
    for (int i = 0; i < output.size(); i++) {
        for (int j = 0; j < output[0].size(); j++)
        {
            long double sum = 0;
            for (int k = 0; k < inputmxk.size(); k++) {
                sum += inputnxm[i][k] * inputmxk[k][j];
            }
            output[i][j] = sum;
        }
    }
    return output;
}

vector<long double> dot(const vector<long double>& input1xm, const vector<vector<long double> >& inputmxk) {
    assert(input1xm.size() == inputmxk.size() && !input1xm.empty(), "size mismatch for dot");
    vector<long double> output = vector<long double>(inputmxk[0].size());
    for (int i = 0; i < output.size(); i++) {
        long double sum = 0;
        for (int k = 0; k < inputmxk.size(); k++) {
            sum += input1xm[k] * inputmxk[k][i];
        }
        output[i] = sum;
    }
    return output;
}

vector<vector<long double> > dot_transpose1(const vector<vector<long double>  >& inputmxn, const vector<vector<long double> >& inputmxk) {
    assert(inputmxn.size() == inputmxk.size() && !inputmxn.empty(), "size mismatch for dot_transpose1");
    vector<vector<long double> > output = vector<vector<long double> >(inputmxn[0].size(), vector<long double>(inputmxk[0].size()));
    for (int i = 0; i < output.size(); i++) {
        for (int j = 0; j < output[0].size(); j++)
        {
            long double sum = 0;
            for (int k = 0; k < inputmxk.size(); k++) {
                sum += inputmxn[k][i] * inputmxk[k][j];
            }
            output[i][j] = sum;
        }
    }
    return output;
}

vector<long double> average_row(const vector<vector<long double> >& input) {
    assert(!input.empty(), "cannot be empty for average_row");
    vector<long double> output = vector<long double>(input.size());
    for (int i = 0; i < input.size(); i++)
    {
        long double ave = 0;
        for (int j = 0; j < input[i].size(); j++)
        {
            ave += input[i][j];
        }
        output[i] = ave / (long double)input[i].size();
    }
    return output;
}

vector<long double> average_column(const vector<vector<long double> >& input) {
    assert(!input.empty(), "cannot be empty for average_column");
    vector<long double> output = vector<long double>(input[0].size());
    for (int i = 0; i < input[0].size(); i++)
    {
        long double ave = 0;
        for (int j = 0; j < input.size(); j++)
        {
            ave += input[j][i];
        }
        output[i] = ave / (long double)input.size();
    }
    return output;
}

vector<vector<long double> > transpose(const vector<vector<long double>  >& input) {
    assert(!input.empty(), "cannot be empty for transpose");
    vector<vector<long double> > output = vector<vector<long double> >(input[0].size(), vector<long double>(input.size()));
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            output[i][j] = input[j][i];
        }
    }
    return output;
}

vector<vector<long double> > mult(const vector<vector<long double>  >& input1, const vector<vector<long double> >& input2) {
    assert(input1.size() == input2.size() && input1[0].size() == input2[0].size() && !input1.empty(), "size mismatch for add");
    vector<vector<long double> > output = vector<vector<long double> >(input1.size(), vector<long double>(input1[0].size()));
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[0].size(); j++)
        {
            output[i][j] = input1[i][j] * input2[i][j];
        }
    }
    return output;
}

vector<vector<long double> > scale(const vector<vector<long double> >& input, long double constant) {
    assert(!input.empty(), "cannot be empty for scale");
    vector<vector<long double> > output = vector<vector<long double> >(input.size(), vector<long double>(input[0].size()));
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[0].size(); j++)
        {
            output[i][j] = input[i][j] * constant;
        }
    }
    return output;

}


vector<long double> scale(const vector<long double>& input, long double constant) {
    assert(!input.empty(), "cannot be empty for scale");
    vector<long double> output = vector<long double>(input.size());
    for (int i = 0; i < input.size(); i++)
    {

        output[i] = input[i] * constant;

    }
    return output;

}

vector<vector<long double> > getrow(const vector<vector<long double> >& input, int index) {
    assert(!input.empty() && input[0].size() > index && index >= 0, "invalid index for getrow");
    vector<vector<long double> > output = vector<vector<long double> >(input.size(), vector<long double>(1));
    for (int i = 0; i < output.size(); i++) {
        output[i][0] = input[i][index];
    }
    return output;
}


vector<vector<long double> > getcolumn(const vector<vector<long double> >& input, int index) {
    assert(!input.empty() && input.size() > index && index >= 0, "invalid index for getcolumn");
    vector<vector<long double> > output = vector<vector<long double> >(1, vector<long double>(input[0].size()));
    for (int i = 0; i < output[0].size(); i++)
    {
        output[0][i] = input[index][i];
    }
    return output;
}

vector<vector<long double> > getrows(const vector<vector<long double> >& input, int start_index, int end_index) {
    assert(!input.empty() && input[0].size() > end_index && start_index >= 0 && start_index < end_index, "invalid indexes for getrows");
    vector<vector<long double> > output = vector<vector<long double> >(input.size(), vector<long double>(end_index - start_index + 1));
    for (int j = start_index; j <= end_index; j++)
    {
        for (int i = 0; i < output.size(); i++) {
            output[i][j - start_index] = input[i][j];
        }
    }
    return output;
}

vector<vector<long double> > getcolumns(const vector<vector<long double> >& input, int start_index, int end_index) {
    assert(!input.empty() && input.size() > end_index && start_index >= 0 && start_index < end_index, "invalid indexes for getcolumns");
    vector<vector<long double> > output = vector<vector<long double> >(end_index - start_index + 1, vector<long double>(input[0].size()));
    for (int j = start_index; j <= end_index; j++)
    {
        for (int i = 0; i < output[0].size(); i++)
        {
            output[j - start_index][i] = input[j][i];
        }
    }
    return output;

}
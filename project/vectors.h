#ifndef VECTORS_H
#define VECTORS_H

#include <vector>

using namespace std;

void assert(bool check, const char* error_message);

int max_index(const vector<long double>& input);

void print_size(const vector<vector<long double> >& input);

void print_size(const vector<long double>& input);

void print(const vector<vector<long double> >& input);

void print(const vector<long double>& input);

void print_visual(const vector<long double>& input, int row_size);

vector<vector<long double> > sub(const vector<vector<long double> >& input1, const vector<vector<long double> >& input2);

vector<long double> sub(const vector<long double>& input1, const vector<long double>& input2);

vector<vector<long double> > add(const vector<vector<long double> >& input1, const vector<vector<long double> >& input2);

vector<vector<long double> > dot(const vector<vector<long double>  >& inputnxm, const vector<vector<long double> >& inputmxk);

vector<long double> dot(const vector<long double>& input1xm, const vector<vector<long double> >& inputmxk);

vector<long double> average_column(const vector<vector<long double> >& input);

vector<long double> average_row(const vector<vector<long double> >& input);

vector<vector<long double> > transpose(const vector<vector<long double>  >& input);

vector<vector<long double> > dot_transpose1(const vector<vector<long double>  >& inputmxn, const vector<vector<long double> >& inputmxk);

vector<vector<long double> > mult(const vector<vector<long double>  >& input1, const vector<vector<long double> >& input2);

vector<vector<long double> > scale(const vector<vector<long double> >& input, long double constant);

vector<long double> scale(const vector<long double>& input, long double constant);

vector<long double> getrow(const vector<vector<long double> >& input, int index);

vector<long double> getcolumn(const vector<vector<long double> >& input, int index);

vector<vector<long double> > getrows(const vector<vector<long double> >& input, int start_index, int end_index);

vector<vector<long double> > getcolumns(const vector<vector<long double> >& input, int start_index, int end_index);

#endif
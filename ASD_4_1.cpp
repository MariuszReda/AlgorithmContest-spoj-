#ASD_4_1 - Multiply matrix transposition by vector

/*
There is a table with real numbers. The table consists of m rows and n + 1 columns. 
The next n columns of the table represent a matrix X, and the n n + 1st column is a representation of the vector y.

Write a program that finds the product of XY.

INPUT
The program entry includes the following items:

n - natural number 1 ≤ n ≤ 25, specifying the number of columns of matrix X,
m - natural number 5 ≤ m ≤ 1000, specifying the number of data lines,
m × (n + 1) table with real numbers separated by spaces:

x11   x12   ...   x1n   y1
x11   x12   ...   x1n   y2
...   ...   ...   ...   ...
xm1   xm2…  ...   xmn   ym

OUTPUT
The output of the program should include the result of multiplying the transposition of a given matrix X by a given vector y.
*/

#include <iostream>

using namespace std;

int main() {
    double** M;
    double** Mt;
    double* W;
    int Columns, Rows;

    cin >> Columns;
    cin >> Rows;

    M = new double* [Rows];
    Mt = new double* [Columns];
    for (int i = 0; i < Rows; ++i)
    {
        M[i] = new double[Columns];
    }
    for (int i = 0; i < Columns; ++i)
    {
        Mt[i] = new double[Rows];
    }
    W = new double[Rows] {};

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Columns; j++) {
            cin >> M[i][j];
        }
        cin >> W[i];
    }

    for (int l = 0; l < Columns; l++) {
        for (int i = 0; i < Rows; i++) {
            Mt[l][i] = M[i][l];
        }
    }

    double* Result = new double[Columns];
    double Calculation = 0;
    for (int i = 0; i < Columns; i++) {
        Calculation = 0;
        for (int j = 0; j < Rows; j++) {
            Calculation += Mt[i][j] * W[j];
        }
        Result[i] = Calculation;
    }

    for (int m = 0; m < Columns; m++) {
        printf("%.10g", Result[m]);
        cout << " ";
    }

    return 0;
}

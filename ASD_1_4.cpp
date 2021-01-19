#ASD_1_4 - Matrix ratio
/*
Given is a rectangular matrix X, containing integers, consisting of m rows and n columns. The number of rows and columns is 100 or less.

One should write a program that finds the product of the XTX matrix.

INPUT
In the first input line there is an integer m ∈ [1; 100] specifying the number of rows of the X matrix. 
In the second input line there is an integer n ∈ [1; 100] specifying the number of columns in the X matrix. 
In the following m lines there are n integers from the range [-100; 100], separated by a space, which define elements of the matrix X.

OUTPUT
The output XTX matrix should be written.
*/

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
vector<vector<int>> GetMatrix(int rows, int columns)
{
	vector<vector<int>> matrix;
	for (int i = 0; i < rows; i++)
	{
		vector<int> row;
		for (int j = 0; j < columns; j++)
		{
			int num;
			cin >> num;
			row.push_back(num);
		}
		matrix.push_back(row);
	}
	return matrix;
}
vector<vector<int>> Transpose(vector<vector<int>> matrix, int rows, int columns)
{
	vector<vector<int>> transposedMatrix;
	for (int i = 0; i < columns; i++)
	{
		vector<int> row;
		for (int j = 0; j < rows; j++)
		{
			row.push_back(matrix[j][i]);
		}
		transposedMatrix.push_back(row);
	}
	return transposedMatrix;
}
vector<vector<int>> Multiply(vector<vector<int>> A, vector<vector<int>> B, int rows, int columns)
{
	vector<vector<int>> C;


	for (int i = 0; i < columns; i++)
	{
		vector<int> row;

		for (int j = 0; j < columns; j++)
		{
			int sum = 0;
			for (int k = 0; k < rows; k++)
			{
				sum += A[i][k] * B[k][j];

			}
			row.push_back(sum);
		}
		C.push_back(row);
	}
	return C;
}
void Display(vector<vector<int>> matrix,int rows,int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << matrix[i][j] << " ";
			if (j == columns - 1)
			{
				cout << "\n";
			}
		}
	}
}

int main()
{
	
	int m;
	int n;
	cin >> m;
	cin >> n;
	vector<vector<int>> A = GetMatrix(m, n);
	vector<vector<int>> B = Transpose(A,m, n);
	vector<vector<int>> C = Multiply(B,A,m, n);
	Display(C,n,n);

	return 0;
}

##ASD_1_1 - Maximum number
/*
The given sequence of non-negative integers terminating in zero is given, where zero is not an element of the string.

Find the maximum number in a given string.

INPUT
There is a sequence of non-negative integers in the range [1; 100], terminated with zero. Zero is used to determine the end of the string, therefore it will occur exactly once in the input. Each element of the string is given on a separate line.

OUTPUT
The output should be the value of the maximum number in the given string.
*/

#include <iostream>
using namespace std;

int main()
{	
	unsigned x;
	int max= 0;
	
	do
	{
		cin >> x;
		if (x > max)
			max = x;
	} while (x != 0);
	cout << max;
}

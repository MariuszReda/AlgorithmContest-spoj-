#ASD_1_2 - Minimum number

/*
A zero-terminating sequence of integers is given, where zero is not an element of the sequence. Numbers in the sequence can repeat.

You need to find the minimum number in the string and its last location.

INPUT
The input contains a sequence of integers from the range [-100; 100], ending with zero. Zero is used to determine the end of the string, therefore it will occur exactly once in the input. Each element of the string is given on a separate line.

OUTPUT
The output should contain two integers, the value of the smallest number in a given sequence and its last position, in separate lines.
*/

#include <iostream>
using namespace std;
int main()
{
 
    int min = 100, x = 1 , licznik = 0, licznikb = 0;

    for (int i = 0; i = x; i) {
        cin >> x;
        licznik++;
        if (x <= min && x != 0) {
            min = x;
            licznikb = licznik;
        };
    };
    cout << min << endl;
    cout << licznikb;
}

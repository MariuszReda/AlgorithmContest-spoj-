#ASD_1_3 - The smallest and largest number
/*
A sequence of integers is given. Numbers in the sequence can repeat.

Find the smallest and largest number in the string. For the smallest number, its earliest position in the sequence should be given, and for the highest number, its last position in the sequence.

INPUT
There is a sequence of integers from the range [-500; 500] on the input. Each element of the string is given on a separate line.

OUTPUT
The output should contain four integers on separate lines, meaning in turn:

    1.Value of the smallest number in the given string
    2.The earliest position of the smallest number
    3.Value of the highest number in the given string
    4.Last position of the greatest number
 */
 
 #include <iostream>
using namespace std;

int main()
{
    int n = 1, min = 501, max = -501, licznikmax = 0, licznikmin = 0, licznik = 0;

    while (cin >> n)
    {
        licznik++;
        if (n < min) {
            min = n;
            licznikmin = licznik;
        }
        if (n >= max)
        {
            max = n;
            licznikmax = licznik;
        }
    }
    cout << min << endl << licznikmin << endl << max << endl << licznikmax;
}

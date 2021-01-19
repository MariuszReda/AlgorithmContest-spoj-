#ASD_4_3 - Stack
/*
STOS - Stack
Write a program that simulates the operation of a stack in a 10-element array. 
Initially, the stack is empty and then has to fill or empty according to the commands read from the input.

INPUT
Some undefined number of data sets will be given to the program input. Sets consist of either one line containing the sign - 
(command to take a number from the stack and print it) or two lines, 
the first containing the sign + (the command to put a number on the stack) and the second a small integer. Individual sets will be separated by a newline.

OUTPUT
The output of the program is to appear a string of strings resulting from the execution of commands appearing on the input (if the command was successful,
then print its result: in case of putting a number on the stack, print ':)'; 
in the case of a photograph of a number, its value; on error ':('). Particular strings should be separated with newlines.
*/

#include <iostream>
using namespace std;


int main() {
    int tab[10];
    int i = -1;
    for (int j = 0; j < 10; j++) tab[j] = 0;
    char rezultat;
    int x;

    while (cin >> rezultat)
    {

        if (rezultat == '+')
        {
            
            cin >> x;
            if (i < 9 )
            {
                i++;
                tab[i] = x;
                
                cout << ":)" << endl;
            }
            else cout << ":(" << endl;
        }


        else if (rezultat == '-')
        {
            if (i<10 && i > -1)
            {
                
                cout << tab[i]<<endl;
                i--;
            }
            else
            {
                cout << ":(" << endl;
            }
        }
    }
}

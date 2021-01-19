#ASD_4_2 - Queue
/*
Write a program that simulates a queue in a 10-element array that can hold integers. The queue is empty at the beginning. 
Then, depending on the commands appearing on the input, it has to fill up or empty.

The language handling the queue consists of three commands. The system responds correctly to each command, according to its content,
and then an appropriate message appears on the console informing about the performed action:

1. Enqueue x - the command to put the integer x in the queue. After you try to do it, the following text will appear on a separate line:
    ---> - information about the correct writing of the number x in the queue;
    Error: queue is full - information that because the queue is full, the number x cannot be written to it.
2. Dequeue - command to remove a number from the queue. After you try to do it, the following text will appear on a separate line:
    x - value of the number removed from the queue;
    Error: queue is empty - information that the queue is empty;
3. Print - the command to print the contents of the queue from the head to the tail on the console. After you try to do it, the following will appear on a separate line:
    Print: x1, x2, ..., xn - when the queue is not empty, integers making up the contents of the queue will be printed on the console;
    Print: Queue is empty - the string informs that the queue is empty.
    
INPUT
A number of valid commands will be given to the program input. Each command will be written on one line.

OUTPUT
At the program output, appropriate messages will appear in separate lines, informing about the effects of executed commands.
*/

#include <iostream>
using namespace std;

int main()
{
	string command;
	string tab[10];
	int n = 0;
	int x ;
	int licznik = 0;
	
	while (cin>>command)
	{
		if (command == "Enqueue" && licznik < 10)
		{
			n++;
			x = (10 - n) % 10;
			cin >> tab[x];
			cout << "--->" << endl;
			licznik++;
		}
		else if (command == "Enqueue" && licznik == 10)
		{
			cout << "Error: queue is full " << endl;
			licznik=10;
		}
		
		if (command == "Dequeue" && licznik > 0 )
		{
			n--;
			cout << tab[9] << endl;
			for (int i=9; i>x; i--)
				tab[i] = tab[i-1];
			x++;
			licznik--;
		}
		else if (command == "Dequeue" && licznik == 0) {
			cout << "Error: queue is empty" << endl;
			licznik = 0;
		}

		if (command == "Print")
		{
			cout << "Print: ";
			if (licznik > 0)
			{
				for (int i = 9; i >= x; i--)
					cout << tab[i] << " ";
				cout << endl;
			}
			else
			{
				cout << "Queue is empty"<<endl;
			}
			
		}
	}
	return 0;
}

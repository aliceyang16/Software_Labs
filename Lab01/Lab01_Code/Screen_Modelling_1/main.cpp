// Exercising the Screen class
#include <iostream>
#include "screen.h"

using namespace std;

int main()
{
    Screen myScreen{ 6, 6 };

    myScreen.forward();
    myScreen.set('*');
    myScreen.down();
    myScreen.set('*');
    myScreen.move(3, 3);
    myScreen.set("---");

    myScreen.display();
    cout << endl;

    myScreen.reSize(16, 16);
    myScreen.display();
    myScreen.clear(' ');

    myScreen.move(7, 7);
    myScreen.set("BIG");
    myScreen.move(8, 5);
    myScreen.set("SCREEN");
    myScreen.display();

    // Creating a screen with initial 'A'
    // Exercise 4.1
    Screen initial{ 6, 6 };
    initial.clear(' ');
    for(int i = 1; i < 7; i++)
	{
	    for(int j = 1; j < 7; j++)
		{
		    if((i == 1 && j == 3) || (i == 2 && (j == 2 || j == 4)) || (i == 3 && (j == 1 || j == 5)) ||
		       (i == 4 && j != 6) || (j == 1 && i != 1 && i != 2 && i != 3) ||
		       (j == 5 && i != 1 && i != 2 && i != 3))
			{
			    initial.move(i, j);
			    initial.set('*');
			}
		}
	}

    initial.display();
    cout << endl;

    // Exercise 4.3
    Screen commands{ 10, 10 };
    commands.home();

    for(int i = 0; i <= 4; i++)
	{
	    commands.move(FORWARD);
	    commands.move(DOWN);
	}
    commands.set("You are Here");
    commands.display();
    cout << endl;

    // Exercise 4.4
    Screen wrap{ 6, 6 };
    wrap.move(HOME); // Start at Block (1 ,1)
    wrap.move(UP);   // Move up
    wrap.set("Here"); // Should end up at the bottom of the screen due to wrap around.
    wrap.display();
    cout << endl;

    // Exercise 4.5
    Screen Square{ 20, 20 };
    // Square.clear(' ');
    Square.square(2, 2, 10); // pass (row, colomn, square size)
    Square.display();

    return 0;
}
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int prompt_number()
{
    int value; // initialize variable
    cout << "Please enter the secret number: " << endl; // Print instructions
    cin >> value; // Obtain user input

    return value; // return value stored in variable named value
}

int main()
{
    int secret_number = 0; // initializing variables
    int number = 0;

    srand(time(NULL)); // initializing random seed
    secret_number = rand() % 100 + 1;

    int counter = 0;
    while(counter != 5)
	{
	    number = prompt_number(); // call prompt_number function

	    if(number == secret_number) // test if number is equal to the secret number
		{
		    cout << "You win!" << endl;
		    break;
		}
	    else if(number > secret_number) // else test if number is greater than secret number
		{
		    cout << "Guess Lower." << endl;
		}
	    else if(number < secret_number) // else test if number is less than the secret number
		{
		    cout << "Guess Higher." << endl;
		}
	    counter++; // increment counter
	}

    if(number != secret_number)
	{
	    cout << endl;
	    cout << "You lose!" << endl;
	    cout << "This secret number is: " << secret_number << endl;
	}

    return 0;
}

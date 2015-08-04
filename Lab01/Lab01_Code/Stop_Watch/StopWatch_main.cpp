#include <iostream>
#include <ctime>
#include <StopWatch.h>

using namespace std;

int main()
{
	
	StopWatch testWatch;	// creating an object
	char button;
	double time = 0;
	cout << "Instructions: Press 's' to start the Stop Watch, 'Enter' to Lap Time, and 'n' to stop Stop Watch" << endl;
	cin >> button;
	
	//If statement tests whether the user has made a request to start the start watch
	if (testWatch.startStopWatch(button) == true)
	{
		cout << "Start! \n" << endl;
		// Run while loop until the user makes a request to stop the stop watch
		while (button != 'n')
		{
			time = testWatch.getProcessTime();
			
			if ((button = cin.get()) == '\n')
			{
				testWatch.lapTime(time);
			}
		}
	}
	
	testWatch.stopStopWatch(time);
	return 0;
}
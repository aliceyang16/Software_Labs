#include <iostream>
#include <ctime>
#include <StopWatch.h>

using namespace std;

int main()
{
	
	StopWatch testWatch;	// creating an object
	char button;
	double time;
	cout << "Press 's' to start Stop Watch" << endl;
	cin >> button;

	if (testWatch.startStopWatch(button) == true)
	{
		cout << "Start!" << endl;
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
#include <iostream>
#include <ctime>
#include <StopWatch.h>

using namespace std;

double getProcessTime()
{
	clock_t time = clock();
	return static_cast<double>(time)/CLOCKS_PER_SEC;
}

int main()
{
	
	StopWatch testWatch;	// creating an object
	//char button = 's';
	//cout << "Press any key (but 's') to start stop watch" << endl;
	//cin >> button;
	
	int button = 0;
	while (button != 100)
	{
		testWatch.startStopWatch();
		button ++;
	}
	
	testWatch.stopStopWatch();
	testWatch.recordedTime();
	
	cout << getProcessTime() << endl;
	
	return 0;
}

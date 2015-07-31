#include <iostream>
#include <time.h>
#include <StopWatch.h>

using namespace std;

StopWatch::StopWatch()	// Constructor
{

}

bool StopWatch::startStopWatch(char& button)
{
	bool start = false;
	if ((button == 's') || (button == 'S'))
	{
		start = true;
	}
	return start;
}

void StopWatch::lapTime(double& time)
{
	cout << "Lap Time: " << time  << "s" << endl;
}

void StopWatch::stopStopWatch(double& time)
{
	cout << "Stop! \n" << endl;
	cout << "Total Time: " << time << "s" << endl;
}

double StopWatch::getProcessTime()
{
	clock_t time = clock();
	return static_cast<double>(time)/CLOCKS_PER_SEC;
}
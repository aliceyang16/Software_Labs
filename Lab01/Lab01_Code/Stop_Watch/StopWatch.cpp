#include <iostream>
#include <time.h>
#include <StopWatch.h>

using namespace std;

StopWatch::StopWatch() // Constructor
{
}

// Starts the StopWatch when a request for it to start has been made
bool StopWatch::startStopWatch(char& button)
{
    bool start = false;
    if((button == 's') || (button == 'S'))
	{
	    start = true;
	}
    return start;
}

// Fetches the current lap time when requested
void StopWatch::lapTime(double& time)
{
    cout << "Lap Time: " << time << "s" << endl;
}

// Gets the total time after the user has requested to stop the stopwatch
void StopWatch::stopStopWatch(double& time)
{
    cout << "Stop! \n" << endl;
    cout << "Total Time: " << time << "s" << endl;
}

// returns the time recored to type double variable
double StopWatch::getProcessTime()
{
    clock_t time = clock();
    return static_cast<double>(time) / CLOCKS_PER_SEC;
}
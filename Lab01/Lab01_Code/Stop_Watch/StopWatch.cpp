#include <iostream>
#include <time.h>
#include <StopWatch.h>

using namespace std;

StopWatch::StopWatch()	// Constructor
{

}

void StopWatch::startStopWatch()
{
	start = time(NULL);
}

void StopWatch::stopStopWatch()
{
	now = time(NULL);
}

void StopWatch::recordedTime()
{
	seconds = difftime(now, start);
	cout << "Time Recorded: " << seconds << "s" << endl;
}

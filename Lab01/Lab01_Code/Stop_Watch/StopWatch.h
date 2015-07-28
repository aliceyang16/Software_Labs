#ifndef STOPWATCH_H_INCLUDED
#define STOPWATCH_H_INCLUDED

class StopWatch
{
public:
	StopWatch();
	void startStopWatch();
	void stopStopWatch();
	void recordedTime();
	
private:
	time_t start;
	time_t now;
	double seconds;
};


#endif // STOPWATCH_H_INCLUDED
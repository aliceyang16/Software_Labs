#ifndef STOPWATCH_H_INCLUDED
#define STOPWATCH_H_INCLUDED

class StopWatch
{
public:
    StopWatch();
    bool startStopWatch(char&);
    void lapTime(double&);
    void stopStopWatch(double&);
    double getProcessTime();

private:
    char button;
    double time;
};

#endif // STOPWATCH_H_INCLUDED
#ifndef DATE_H
#define DATE_H
// date.h
// class Date declaration

#include <cassert>
#include <iostream>
using namespace std;

enum class Month 
{
	January = 1, 
	February,
	March, 
	April,
	May,
	June,
	July, 
	August, 
	September,
	October,
	November, 
	December
};

// empty class to represent exceptions
class InvalidDate{};
	
class Date
{
public:	

	//This is the defined default constructor, client didnt input data
	Date();	
	//This is the constructor for when client inputs data 	
	Date(int day, Month month, int year);
	//create a static or default member of Date 
	static Date _default;
	//set the Default member function
	static void setDefaultDate(int day, Month month, int year);
	// return the day of the month
	int	day () const;
	// return the month of the year
	Month month () const;
	// return the year
	int year () const;
	// return true if it is a leap-year, false if not
	bool isLeapYear () const;	
	
	bool operator==(const Date& rhs)const;
	
	void nextDay (); 

private:

	//create a static or default member of Date 
	//static Date _default;
	// return the number of days in the _month
	int	daysInMonth () const;	//const doesnt allow for change of data members thats why in private  
	int	_day;
	Month _month;
	int	_year;

};

// standalone function for printing the date
void printDate(const Date& date);



#endif
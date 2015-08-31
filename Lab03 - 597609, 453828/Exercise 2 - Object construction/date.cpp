// date.cpp
// Implementation of the Date class

#include "date.h"

Date::Date()
{}

//Default date put into constructor  
Date Date::_default{1, Month::January, 1900};

void Date::setDefaultDate(int day, Month month, int year)
{
	_default = {day, month, year};
}

Date::Date(int day, Month month, int year)
	: _day{day}, _month{month}, _year{year}
	{
		if(_day > daysInMonth() || _day < 1)
			{
				throw InvalidDate();
			}
	}

int Date::day() const
{
	return _day;
}

Month Date::month() const
{
    return _month;
}

int Date::year() const
{
	return _year;
}

bool Date::isLeapYear() const
{
    // leap years must be divisible by 4 but not by 100
    // or divisible by 400
    if(((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0))
        return true;
    else
        return false;
}

 Date::daysInMonth() const
{
	switch (_month) {
		case Month::January: 
		case Month::March: 
		case Month::May: 
		case Month::July:
		case Month::August: 
		case Month::October: 
		case Month::December:
			return 31;	
		case Month::April: 
		case Month::June: 
		case Month::September:
		case Month::November:
			return 30;	
		case Month::February:
			if ( isLeapYear() ) return 29;
			else return 28;
		default:
			// should never reach here
			assert(false);
	}
}

void Date::nextDay()
{
		if (_day < daysInMonth()) 
		{
			_day ++;
		}		

		else
			
		{
			if (_month != Month::December)
			{
				int numberAsMonth = static_cast<int>(_month);
				numberAsMonth ++;
				_day = 1;
				_month = static_cast<Month>(numberAsMonth); 
			}
			
			else 
			{
				int numberAsMonth = static_cast<int>(_month);
				_year ++;
				numberAsMonth = 1;
				_day = 1;
				_month = static_cast<Month>(numberAsMonth); 
			}			
		}
		
		
}

// Note, this standalone function is not part of the Date class
void printDate(const Date& date)
{
	cout << date.day() << "/"
		// cast to an integer to allow the month to be sent to the stream
        << static_cast<int>(date.month()) << "/"
		<< date.year()
		<< endl;
}

// overloads the equivalence operator which allows for Months to be compared using ==
bool Date::operator==(const Date& rhs) const
{
	if ((_day == rhs._day) && (_month == rhs._month) && (_year == rhs._year))
		return true;
	else
		return false;
}


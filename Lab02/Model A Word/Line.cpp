// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"
Line::Line(const string& line)
    : _line{ line }
{
    // Hint: some of string's member functions might come in handy here
    // for extracting words.
}

bool Line::contains(const Word& search_word) const
{
    bool test = false;
    if(_line.empty())
		test = false;
    else if(search_word == _line)
		test = true;
    else;
	
    return test;
}
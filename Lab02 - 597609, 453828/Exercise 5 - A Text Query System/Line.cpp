// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"
Line::Line(const string& line)
    : _line{ line }
{
    // Hint: some of string's member functions might come in handy here
    // for extracting words.
	
	// istringstream reads in _line and separates each word in line. The word is stored into 
	// temp_word and the word is stored as a whole into the string vector. This means that each 
	// element in the string vector is a word instead of characters.
	string temp_word;
	istringstream iss;
	iss.str(_line); 
	
	while (iss >> temp_word)
	{
		temp_line_word.push_back(temp_word);
	}
}

bool Line::contains(const Word& search_word) const
{
    bool test = false;
	
    if(_line.empty())
		test = false;
    else 
	{
		for(auto word_iterator = temp_line_word.begin(); word_iterator != temp_line_word.end(); word_iterator++)
		{
			Word temp_line(*word_iterator);
			if(search_word == temp_line)
			{
				test = true;
			}
		}
	}
	
	if (search_word.isQueryable() == false)
		test = false;
		
    return test;
}

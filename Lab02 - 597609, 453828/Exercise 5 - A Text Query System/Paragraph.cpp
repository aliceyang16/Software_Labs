// -------------------------------------------
//					Paragraph
// -------------------------------------------

#include "Paragraph.h"

void Paragraph::addLine(const Line& line)
{
    _paragraph.push_back(line);
}

bool Paragraph::contains(const Word& search_word, vector<int>& line_numbers) const
{
	bool test = false;
	unsigned int line_counter = 0;
	
	for (auto temp_line : _paragraph)
	{
		line_counter ++;
		if (temp_line.contains(search_word) == true)
		{
			test = true;
			line_numbers.push_back(line_counter);
		}
	}
	return test;
}
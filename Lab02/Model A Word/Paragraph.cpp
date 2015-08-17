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
    auto paragraph_iterator = _paragraph.begin();

    while(paragraph_iterator != _paragraph.end())
	{
	    if(*paragraph_iterator.contains(search_word) == true)
		{
		    return true;
		}
	    else
			return false;
			
		paragraph_iterator++;
	}

}
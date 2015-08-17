// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"
const int MIN_SIZE_FOR_QUERY = 3;

Word::Word(const string& word)
    : _word{ word }
{
    // throws an exception (in the form of WordContainsNoLetters object)
    // indicating that the word being constructed contains no letters
    if(_word.empty())
		throw WordContainsNoLetters();
    else
	{
	    unsigned int punctuation_counter = 0;
	    unsigned int space_counter = 0;

	    auto iterator = _word.begin();
	    while(iterator != _word.end())
		{
		    *iterator = tolower(*iterator);

		    if(ispunct(*iterator))
			{
			    _word.erase(iterator); // removes punctuation in _word
			    iterator--;
			    punctuation_counter++;
			}
		    else if(isspace(*iterator))
			{
			    space_counter++;
			}

		    iterator++;
		}

	    if(punctuation_counter == word.size())
		{
		    throw WordContainsNoLetters();
		}

	    if(space_counter > 0)
		{
		    throw WordContainsSpace();
		}
	}

    // Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows two Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
    bool test = false;

    if(_word == rhs._word)
		test = true;
    else
		test = false;
		
    return test;
}

bool Word::isQueryable() const
{
    if(_word.size() >= MIN_SIZE_FOR_QUERY)
		return true;
    else
		return false;
}
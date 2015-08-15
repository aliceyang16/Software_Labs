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
	    for(auto iterator = _word.begin(); iterator != _word.end(); iterator++)
		{
		    if(ispunct(*iterator))
			{
			    punctuation_counter++;
			}
		    else if(isspace(*iterator))
			{
			    space_counter++;
			}
		}
		
	    if(punctuation_counter == _word.size())
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
    bool test;

    auto word_1 = _word;
    auto word_2 = rhs._word;

    auto iterator1 = word_1.begin();
    auto iterator2 = word_2.begin();

    int punctuation_counter = 0;

    if(_word == rhs._word)
	test = true;
    else
	{
	    while(iterator1 != word_1.end() && iterator2 != word_2.end())
		{
		    if(ispunct(*iterator1))
			{
			    word_1.erase(iterator1);
			    iterator1--;
			    iterator2--;
			    punctuation_counter++;
			}
		    else if(ispunct(*iterator2))
			{
			    word_2.erase(iterator2);
			    iterator1--;
			    iterator2--;
			    punctuation_counter++;
			}

		    if(tolower(*iterator2) != towlower(*iterator1))
			{
			    test = false;
			}
		    else
				test = true;

		    iterator1++;
		    iterator2++;
		}
	}
    return test;
}

bool Word::isQueryable() const
{
    if(_word.size() >= MIN_SIZE_FOR_QUERY)
		return true;
    else
		return false;
}
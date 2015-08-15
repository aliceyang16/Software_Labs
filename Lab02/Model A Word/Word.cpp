// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"

Word::Word(const string& word)
    : _word{ word }
{
    // throws an exception (in the form of WordContainsNoLetters object)
    // indicating that the word being constructed contains no letters
    if(_word.empty())
	throw WordContainsNoLetters();

    // Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows two Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
    bool test = false;

    auto word_1 = _word;
    auto word_2 = rhs._word;

    auto iterator1 = word_1.begin();
    auto iterator2 = word_2.begin();

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
			}
		    else if(ispunct(*iterator2))
			{
				word_2.erase(iterator2);
				iterator1--;
				iterator2--;
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
    return false;
}

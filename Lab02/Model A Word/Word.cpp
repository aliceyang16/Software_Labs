// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"
using namespace std;

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

    auto iterator1 = begin(word_1);
    auto iterator2 = begin(word_2);

    test = true;
    if(_word == rhs._word)
	test = true;
    else
	{
	    while(iterator1 != word_1.end())
		{
		    if(tolower(*iterator2) != towlower(*iterator1))
			{
			    test = false;
			}
		    ++iterator1;
		    ++iterator2;
		}
	}
    return test;
}

bool Word::isQueryable() const
{
    return false;
}

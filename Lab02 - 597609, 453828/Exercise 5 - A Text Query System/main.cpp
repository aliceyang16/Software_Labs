// -------------------------------------------
//					main
// -------------------------------------------

#include <iostream>
#include <locale>
#include <string>
#include "Word.h"
#include "Line.h"
#include "Paragraph.h"
#include "FileReader.h"

using namespace std;

int main()
{
    string file_name;
    string user_word;
    bool user_word_terminate = false;
    locale loc;
    bool gate_for_termination;
    bool user_input_punctuation;

    while(user_word_terminate == false)
	{
	    cout << "Please enter file name: ";
	    cin >> file_name;

	    cout << "Please enter a word to search for or '.' to quit: ";
	    cin >> user_word;

	    for(auto it = user_word.begin(); it != user_word.end(); ++it)
		{
		    if(ispunct(*it, loc))
			user_input_punctuation = true;
		    else
			user_input_punctuation = false;
		}

	    if(user_word == ".")
		{
		    gate_for_termination = true;
		    user_word_terminate = true;
		}

	    else
		{
		    gate_for_termination = false;
		    user_word_terminate = false;
		}

	    if((gate_for_termination == false) && (user_input_punctuation == false))
		{
		    FileReader filereader(file_name);
		    Paragraph paragraph;
		    filereader.readFileInto(paragraph);
		    Word search_word(user_word);
		    vector<int> line_numbers;
		    auto t = paragraph.contains(search_word, line_numbers);

		    if(t == true)

			{
			    cout << "Word found: " << endl;

			    for(auto it = line_numbers.begin(); it != line_numbers.end(); ++it)
				cout << "\t     line " << *it << endl;
			}

		    else
			cout << "Word Not found" << endl;
		}

	    else if((gate_for_termination == true) && (user_input_punctuation == true))
		cout << "Terminate!";

	    else
		cout << "Invalid entry!";
	}

    return 0;
}
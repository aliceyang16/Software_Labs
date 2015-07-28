// Tests the compiler and IDE setup. Checks specifically for errors on a Windows CodeLite/TDM-GCC installation.

#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
    auto x = make_unique<int>(7); // If you have a compiler error here check that the C++14 switch is enabled.
    // The line above creates a smart pointer to the value 7. This will be covered later in the course.

    string number;
    cout << "Type in an integer: " << endl;
    cin >> number;
    cout << "You typed: " << number << endl;

    cout << "Your number plus 5 equals " << to_string(stoi(number) + 5) << endl;

    // The functions "to_string" and "stoi", in use above, are very handy when dealing with user input.
    // You can find out more details about how they work at the following urls.
    // http://www.cplusplus.com/reference/string/to_string/
    // http://www.cplusplus.com/reference/string/stoi/

    return 0;
}

#include <iostream>
#include <string.h>
#include <complex>

using namespace std;

typedef complex<double> complex_number;
// Function prototype
int prompt_value(char);
double quad_equation_1(double, int, int);
double quad_equation_2(double, int, int);
complex_number quad_complex_equation(double, int, int);

int main()
{
    char user_input;
    int a_value, b_value, c_value;
    double temp_value = 0;

    while(user_input != 'q')
	{
	    a_value = prompt_value('a');
	    cout << endl;
	    b_value = prompt_value('b');
	    cout << endl;
	    c_value = prompt_value('c');
	    cout << endl;

	    // For the square root value:
	    temp_value = (b_value * b_value) - (4 * a_value * c_value);
	    if(temp_value < 0)
		{
		    complex_number answer;
		    temp_value = abs(temp_value);
		    auto square = sqrt(temp_value);
		    answer = quad_complex_equation(square, a_value, b_value);

		    cout << "x value = " << answer << endl;
		    cout << "or in a familar form" << endl;
		    cout << "x_value = " << answer.real() << " +/- " << answer.imag() << "j" << endl;
		}
	    else
		{
		    auto square = sqrt(temp_value);
		    auto answer_1 = quad_equation_1(square, a_value, b_value);
		    auto answer_2 = quad_equation_2(square, a_value, b_value);

		    if(answer_1 == answer_2)
			{
			    cout << "x value = " << answer_1 << endl;
			}
		    else
			{
			    cout << "x value = " << answer_1 << endl;
			    cout << "or" << endl;
			    cout << "x value = " << answer_2 << endl;
			}
		}

	    cout << "To quite, press q. Otherwise press any key" << endl;
	    cin >> user_input;
	}
}

int prompt_value(char letter)
{
    int value = 0;
    cout << "Please enter value " << letter << ": ";
    cin >> value;

    return value;
}

double quad_equation_1(double square_value, int a_value, int b_value)
{
    double x_value = 0;
    x_value = (-b_value + square_value) / (2 * a_value);
    return x_value;
}

double quad_equation_2(double square_value, int a_value, int b_value)
{
    double x_value = 0;
    x_value = (-b_value - square_value) / (2 * a_value);
    return x_value;
}

complex_number quad_complex_equation(double square_value, int a_value, int b_value)
{
    double real_value;
    double imag_value;
    real_value = -b_value / (2 * a_value);
    imag_value = square_value / (2 * a_value);
    complex_number x_value{ real_value, imag_value };
    return x_value;
}
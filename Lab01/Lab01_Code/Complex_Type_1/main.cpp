#include <iostream>
#include <complex>

using namespace std;

int main()
{
    typedef complex<float> complex_float;

    complex_float num1{ 2.0, 2.0 };
    complex_float num2{ 4.0, -2.0 };

    auto answer = num1 * num2;

    cout << "The answer is: " << answer << endl;
    cout << "Or in a more familar form:" << answer.real() << "+" << answer.imag() << "j" << endl;
}

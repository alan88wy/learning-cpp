//============================================================================
// Name        : learning-cpp.cpp
// Author      : Alan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    cout << "Variables :" << endl;

    int bin_int = 0b0011;

    cout << "Binary Integer 0b0011 = " << bin_int << endl;

    int hex_int = 0x3A;

    cout << "Hex Integer 0x3A = " << hex_int << endl;

    int u_int = 23U;

    cout << "Unsign Integer 23U = " << u_int << endl;

    int o_int = 023;

    cout << "Octal  023 = " << o_int << endl;

    int fl_num = 23.0f;

    cout << "Float 23.0f = " << fl_num << endl;

    char a = 'a';

    cout << "Character " << a << endl;

    // Type Inference with auto

    auto d = 1; // Decimal
    auto f = 1.345f;

    cout << "Type of d (integer): " << typeid(d).name() << endl;        // return i which stands for integer
    cout << "Type of f (floating point): " << typeid(f).name() << endl; // return f which stands for floating point

    d = 't';

    cout << "New d value (t) : " << d << endl; // This will print integer value of the string tru

    return 0;
}

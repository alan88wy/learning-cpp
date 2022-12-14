//============================================================================
// Name        : learning-cpp.cpp
// Author      : Alan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;


#define LOG(msg) \
    std::cout << msg << std::endl;



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

    float fl_num = 23.0f;

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

    // Pointers
    // ========

    const char * message {"Hello World!"};
    cout << "Message : " << message << endl;
    // messag will be an array of character. it will point to the first element.
    // *message will return the first character since it is pointing to the
    // first character in the array.

    cout << "*Message : " << *message << endl;
    cout << "Print second character : " << *(message + 1) << endl;
    cout << "Print third character : " << *(message + 2) << endl;

    // Cannot change the element like message[0] = 'K'
    // but can point to another array
    message = "Welcome";
    cout << "Message : " << message << endl;
    cout << "*Message : " << *message << endl;
    cout << "Print second character : " << *(message + 1) << endl;
    cout << "Print third character : " << *(message + 2) << endl;
    cout << "Print third character : " << *(message + 2) << endl;


    // Reference
    // =========
    // alias to an existing object in memory
    // Reference must be initialized.

    int x1 = 123;
    int& y1 = x1;

    cout << "Value of Y : " << y1 << endl;

    string s = "Helloo World!";

    cout << s.c_str() << endl;

    return 0;
}

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
#include <vector>

using namespace std;


#define LOG(msg) \
    std::cout << msg << std::endl;

int sum(int i, int j);
int incr(int i);
void constReference(const int& i);

class MyClass {

    private:
        int x;
    public:

//        MyClass(int x) {
//            this->x = x;
//        }

        // Member Initialization Class(var): internalVar (var)
        // internalVar = var
        MyClass(int xx): x{xx} {}

        // User defined Copy Constructor
//        when we initialize an object with another object using
//        the = operator on the same line, then the copy operation
//        uses the copy constructor:
//        MyClass copyfrom;
//        MyClass copyto = copyfrom;

        MyClass(const MyClass& rhs): x{rhs.x} {
            cout << "User defined copy constructor invoked!" << endl;
        }

        // Copy Assignment Operator

        // When an object is created on one line and then assigned
        // to in the next line, it then uses the copy assignment
        // operator to copy the data from another object

        // MyClass copyfrom;
        // MyClass copyto;
        // copyto = copyfrom; // uses a copy assignment operator

        MyClass& operator=(const MyClass& rhs) {

            cout << "Copy Assignment Operator called" << endl;

            if (this != &rhs) { // protect against invalid self-assignment
                this->x = rhs.x;
            }

            // *this would be a "clone" of the current object
            return *this;
        }

        // Uder Defined Move constructor
        MyClass(MyClass&& rhs): x{std::move(rhs.x)} {
            cout << "User Defined Move constructor called" << endl;
        }

        // User Defined Move Assignment

        // Move assignment operator is invoked when we declare an
        // object and then try to assign an rvalue reference to it.

        MyClass& operator=(MyClass&& other) {
            cout << "User Defined Move Assignment called" << endl;
            this->x = std::move(other.x);
            return *this;
        }

        // Operator Overloading
        // myobject = otherobject;
        // myobject + otherobject;
        // myobject / otherobject;
        // myobject++;
        // ++myobject;

        // Operator Overloading - prefix operator ++
        MyClass& operator++() {
            ++this->x;
            cout << "Prefix Operator ++ Overloading called" << endl;
            return *this;
        }

        // Operator Overloading - Post operator ++
        MyClass operator++(int) {
            MyClass tmp(*this);  // Create a copy
            operator++(); // Invoke prefix operator

            cout << "Post fix Operator ++ Overloading called" << endl;
            return tmp;
        }

        void setX(int x) {
            this->x = x;
        }

        void printX() {
            cout << "Value of x = " << x << endl;
        }
        int getX() {
            return this->x;
        };
};

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

    // Dynamically allocated storage

    int* p = new int;
    *p = 987;
    cout << "Value of p is : " << *p << endl;
    delete p;


    int* q = new int[3];

    q[0] = 1;
    q[1] = 2;
    q[2] = 3;

    cout << "Value of q is : " << q[0] << ' ' << q[1] << ' ' << q[2] << endl;

    // Reference
    // =========
    // alias to an existing object in memory
    // Reference must be initialized.

    int x1 = 123;
    int& y1 = x1;

    cout << "Value of Y : " << y1 << endl;

    string s = "Helloo World!";

    cout << s.c_str() << endl;

    string subS = s.substr(7, s.length());

    cout << subS.c_str() << endl;

    // finding substring

    /*
     * npos is a static member constant value with the greatest possible value
     * for an element of type size_t. This value, when used as the value for a
     * len (or sublen) parameter in string's member functions, means
     * "until the end of the string".
     *
     * As a return value, it is usually used to indicate no matches.
     *
     * This constant is defined with a value of -1, which because size_t is
     * an unsigned integral type, it is the largest possible representable
     * value for this type.
     *
     */

    string::size_type found = s.find("World");

    if (found != string::npos) {
        cout << "'World' is found at position : " << found << endl;
    } else {
        cout << "'World' is not found";
    }

    // Vector
    // Initialize a vector of size 10 with each element = 5

    vector<int> v1 (10, 5);


    for (auto i=v1.begin(); i < v1.end(); i++) {
        cout << *i << " ";
    }

    cout << endl;

    // Function

    cout << "Sum of 5 and 10  = " << sum( 5, 10) << endl;

    // Pass by reference
    cout << "Increase 5 by 1 : " << incr(5) << endl;

    // Pass by const reference

    int mm = 1;
    constReference(mm);
    cout << "Value of mm (1) after calling constReference(mm) " << mm << endl;

    MyClass myC(100);

//    myC.setX(200);

    myC.printX();

    // Copy constructor will be called
    MyClass myC2 = myC;

//    myC2.printX();



    cout << "Before calling ++myC2" << endl;
    myC2.printX();

    ++myC2;

    cout << "After calling ++myC2" << endl;

    myC2.printX();

    // Move Constructor

    cout << "Move constructor called myC3 = std::move(myC2)" << endl;
    MyClass myC3 = std::move(myC2);
    myC3.printX();

    myC3++;  // Same as myC3.operator++(0);

    cout << "After calling myC3++" << endl;
    myC3.printX();

    return 0;
}

int sum(int i, int j) {
    return i + j;
}

int incr(int i) {
    return ++i;
}

void constReference(const int& i) {
    // This will fail
    // i++;

    return;
}


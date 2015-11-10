C++ Introduction
C++ extends the c language to add objects (and other things such as templates)

Every c program may be compiled with the c++ compiler
On, pyrite use g++ insted of gcc

Example:
    g++ -g -c program.cpp

Note that standard file extension is "cpp"

________BEWARE________
DO NOT COUNT ON SAFETY

It is possible to have pointer to an object that has beet returned to the heap

Does not check array indices
No safety in type casting

Multithreading is not supported as part of the language

Simple Example: HelloWorld
_______________________________
#include <iostream>
using namespace std;

int main(){
    cout << "Hello,World!\n";
    return 0;
}
______________________________
Literals
    1776, 0x4b 75u 75ul 3.1915, 'x'
    /n /t /rf

#define is the same

Move an input/output
    cout << "Samething";
    cout << 120;
    cout << x;
    cout << something << 120 << x << "\n" or <<endl;

you can still use c style input/output

Standard input
    int age;
    cin >> age;

Example:
#include <iostream>

using namespace std{
     int main{
        cout << "Enter age and zipcode";
        int age;
        int zip;
        cin >> age >> zip;
        return 0;
    }
}
Strings in C++

#include <iostream>
#include <String>
using namespace std;
int main(){
    String mystring;
    cout << "What is your name?";
    getline(cin,mystring);
}

C++ reference parameters
Example:
    int i = 7;
    int &j = i;
    j++;
    i += 3; //i == 11 now
    

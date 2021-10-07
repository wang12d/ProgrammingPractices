#include <iostream>

using std::cout;
using std::string;

string 
getString()
{
    string tmp{"hello, world."};
    return tmp;
}

int
main()
{
    const char* x = getString().c_str();
    int a{0};
    cout << a++ << std::endl;
    printf("%s %p\n", x, x);
    cout << x+2 << std::endl;
}
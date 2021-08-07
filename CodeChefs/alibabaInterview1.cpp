#include <iostream>

using std::cin;
using std::endl;
using std::cout;

int
main(int argc, char** argv)
{
    long d, m, w;
    long i, j, k;
    cin >> d >> m >> w;
    cin >> i >> j >> k;
    cout << static_cast<char>(((((j-1) + m * (k-1)) * d + i - 1) % w) + 'a') << endl;
}
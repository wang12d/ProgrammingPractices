#include "Toolbox.h"
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;

double frac(unsigned);

int
main(int argc, char** argv)
{
    Toolbox<int>::timer();
    double lower = log10(1.23), upper = log10(1.24);
    unsigned cnt = 0;
    unsigned target = 678910;
    unsigned res = 0;
    if (argc > 1) sscanf(argv[1], "%ud", &target);
    while (cnt != target) {
        ++res;
        double f = frac(res);
        if (f >= lower && f < upper) cnt++;
    }
    cout << res << endl;
    Toolbox<int>::timeCost();
}

double
frac(unsigned n)
{
    return static_cast<double>(n)*log10(2) - static_cast<int>(static_cast<double>(n)*log10(2));
}
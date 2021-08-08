#include "Toolbox.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using Timer = Toolbox<int>;
using std::cin;
using std::cout;
using std::endl;
const double EPSILON = 1e-25;

double 
total_digital(double x)
{
    double val = 0.0;
    while (x - 1 >= EPSILON) {
        val += 1;
        x /= 10;
    }
    return val;
}

bool
valid_sequence(double real_val)
{
    double a = floor(real_val), b = real_val;
    long decimal = 0;
    for (;;) {
        b = floor(b) * (b-floor(b)+1);
        decimal += total_digital(b);
        cout << a << " floor: " << floor(b)*(pow(10, -decimal)) << endl;
        a = a + floor(b)*(pow(10, -decimal));
        if (a - real_val > pow(10, -decimal-1)) {
            return true;
        }
        else if (a - real_val < pow(10, -decimal-1)) {
            return false;
        }
    }
}


int
main(int argc, char** argv)
{
    double lo = 2.0, hi = 3.0;
    long loop = 10;
    cout << std::fixed;
    cout << std::setprecision(30);
    while (loop--) {
        double mid = ((hi + lo) / 2);
        if (valid_sequence(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << ' ' << lo << endl;
}
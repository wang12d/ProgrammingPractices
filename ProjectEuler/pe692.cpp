#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int
main(int argc, char** argv)
{
    unsigned long input;
    sscanf(argv[1], "%lud", &input);
    unsigned long prevOneFib = 0;
    unsigned long a = 1, b = 1;
    unsigned long preSum = 0;
    unsigned long res = 0;
    for (unsigned long i = 1; b <= input; i++) {
        auto tmpRes = res;
        auto tmpFib = b;
        res += preSum + b - (i > 2 ? prevOneFib : 0 );
        b += a;
        prevOneFib = a;
        a = tmpFib;
        preSum = tmpRes;
    }
    cout << res << endl;
}
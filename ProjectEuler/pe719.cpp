#include <iostream>

using std::cout;

static bool
isAddable(unsigned long n, unsigned long rem)
{
    if (n == rem) {
        return true;
    } else if (n > rem) {
        bool res = false;
        for (unsigned long i = 10;i <= n && !res; i *= 10) {
            res |= isAddable(n/i, rem-(n%i));
        }
        return res;
    } else {
        return false;
    }
}

int
main(int argc, char** argv)
{
    const unsigned long maxn = 1e12;
    unsigned long res = 0;
    unsigned long square;
    for (unsigned long i = 2; (square = i*i) <= maxn; ++i) {
        if (isAddable(square, i)) {
            res += square;
        }
    }
    cout << res << std::endl;
}
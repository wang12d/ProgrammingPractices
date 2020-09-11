#include "Toolbox.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
long sum_digit_sum(long, long, long);

const long MOD = 1000000007L;
const int MAXDIGIT = 9;
int
main(int argc, char** argv)
{
    Toolbox<int>::timer();
    long k = 90;
    const long de = 2;
    if (argc > 1) {
        k = atol(argv[1]);
    }
    long mod_inv, tmp;
    Toolbox<long>::extendGCD(de, MOD, &mod_inv, &tmp);
    if (mod_inv < 0) mod_inv += MOD;
    long res = -1; // The problem need from f_2 to f_90
    // Compute fibonacci numbers
    vector<long> fibs(k, 1);
    for (auto i = 2; i < k; ++i) {
        fibs[i] = fibs[i-1] + fibs[i-2];
    }
    for (auto i: fibs) {
        res = (res + sum_digit_sum(1, i, mod_inv)) % MOD;
    }
    cout << res << endl;
    Toolbox<int>::timeCost();
}

long
sum_digit_sum(long n, long m, long mod_inv)
{
    auto r = n % MAXDIGIT;
    auto d = n / MAXDIGIT;
    auto x = m % MAXDIGIT;
    auto y = m / MAXDIGIT;

    long res = 5 * (Toolbox<long>::powerWithMOD(10, y, MOD) - Toolbox<long>::powerWithMOD(10, d+1, MOD)) % MOD;
    res = res - 9 * (y - d - 1) % MOD;
    res = res + (mod_inv * (10 + r) * (9 - r) % MOD) * Toolbox<long>::powerWithMOD(10, d, MOD) % MOD;
    res = res - (9 - r);
    res = res + (mod_inv * (x + 2) * (x + 1) % MOD) * Toolbox<long>::powerWithMOD(10, y, MOD) % MOD;
    res = res - (x + 1);
    return res % MOD;
}

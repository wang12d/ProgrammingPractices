#include <bits/stdc++.h>
#include "Toolbox.h"

using namespace std;
using ull = unsigned long long;
using tll = Toolbox<ull>;

const ull MOD{static_cast<ull>(1e9+7)};

int
main(int argc, char** argv)
{
    tll::timer();

    ull n{static_cast<ull>(1e8)};
    if (argc > 1) {
        sscanf(argv[1], "%llu", &n);
    }
    vector<ull> primes{tll::findPrimes(n)};
    ull ans{2};
    for (ull& p: primes) {
        ull tmp{p};
        while (tmp <= n) {
            tmp *= p;
        }
        ans = ans * (tmp / p) % MOD;
    }

    cout << ans << endl;

    tll::timeCost();
}
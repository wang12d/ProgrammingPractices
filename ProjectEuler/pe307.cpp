#include <bits/stdc++.h>
#include "Toolbox.h"

using namespace std;
using ld = long double;
using ull = unsigned long long;
using tll = Toolbox<ull>;

ld
log_factorial(ull n, ull k=1)
{
    ld ans{0.0};
    for (ull i{k+1}; i <= n; ++i) {
        ans += log(i);
    }
    return ans;
}

int
main(int argc, char** argv)
{
    tll::timer();
    ull k{static_cast<ull>(1e4*2)};
    ull n{static_cast<ull>(1e6)};

    if (argc > 2) {
        sscanf(argv[1], "%llu", &k);
        sscanf(argv[2], "%llu", &n);
    }

    ld p{1.0/static_cast<ld>(n)};
    ld ans{0}; ull half_defects{k>>1};
    for (ull x{0}; x <= half_defects; ++x) {
        ans += exp(log_factorial(n, n-k+x) + log_factorial(k, k-2*x) - log_factorial(x) - x*log(2) - k*log(n));
    }
    printf("%.10Lf\n", 1-ans);
    tll::timeCost();
}
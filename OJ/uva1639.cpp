#include <cmath>
#include <vector>
#include <iostream>

using std::cin;
using std::vector;

static const int maxn{200000+1};

using ld = long double;

vector<ld> factorial(maxn, 0.0);

ld
comb(int n, int m)
{
    return factorial[n]-factorial[m]-factorial[n-m];
}

ld
findExceptedCandies(ld n, ld p)
{
    ld ans{.0};
    for (int remain{0}; remain <= n; ++remain) {
        ld c{comb(2*n-remain, n-remain)};
        ld left{c+(n+1)*log(p)+(n-remain)*log(1-p)};
        ld right{c+(n+1)*log(1-p)+(n-remain)*log(p)};
        ans += remain * (exp(left)+exp(right));
    }
    return ans;
}

int
main()
{
    for (int i{2}; i < maxn; ++i) {
        factorial[i] = factorial[i-1] + log(i);
    }
    int n; ld p; int k{0};
    while (cin >> n >> p) {
        printf("Case %d: %.6Lf\n", ++k, findExceptedCandies(n, p));
    }
}
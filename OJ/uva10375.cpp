#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


void
calcPrimeExpt(int n, bool neg, vector<int>& primes, vector<int>& expt)
{
    size_t sz{primes.size()};
    for (size_t i{0}; i < sz; ++i) {
        int p{primes[i]};
        while (p <= n) {
            if (neg) {
                expt[i] -= n / p;
            } else {
                expt[i] += n / p;
            }
            p = primes[i] * p;
        }
    }
}

int
main()
{
    static const int maxn{10000};
    vector<int> primes;
    vector<bool> notprime(maxn+1, false);
    notprime[0] = notprime[1] = true;
    for (int i{2}; i*i <= maxn; ++i) {
        if (!notprime[i]) {
            for (int j{i*i}; j <= maxn; j += i) {
                notprime[j] = true;
            }
        }
    }
    for (int i{2}; i <= maxn; ++i) {
        if (!notprime[i]) {
            primes.push_back(i);
        }
    }

    int p, q, r, s;
    auto psz{primes.size()};
    vector<int> expt(psz, 0);
    while (cin >> p >> q >> r >> s) {
        std::fill(expt.begin(), expt.end(), 0);
        calcPrimeExpt(p, false, primes, expt);
        calcPrimeExpt(r-s, false, primes, expt);
        calcPrimeExpt(s, false, primes, expt);
        calcPrimeExpt(p-q, true, primes, expt);
        calcPrimeExpt(q, true, primes, expt);
        calcPrimeExpt(r, true, primes, expt);
        double ans{1.0};
        for (auto i{0}; i < psz; ++i) {
            ans *= pow(static_cast<double>(primes[i]), static_cast<double>(expt[i]));
        }
        printf("%.5lf\n", ans);
    }
}
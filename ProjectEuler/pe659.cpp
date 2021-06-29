#include <bits/stdc++.h>
#include "Toolbox.h"

using ul = unsigned long;
using std::cout;
using std::endl;
using std::max;
using std::unordered_set;
using std::vector;


template <typename T>
std::vector<T>
findPrimes(const T& n)
{
      T i, j;  // use long in case overflow
      std::vector<bool> is_prime(n+1, true);
      std::vector<T> primes;
      is_prime[0] = is_prime[1] = false;
      for (i = 2; i*i <= n; ++i) {
            if (is_prime[i]) {
                  // all the number that contain i as factor has
                  // been marked, thus the smallest number is i*i
                  // j > 0 in case the overflow
                  for (j = i*i; j <= n; j += i) {
                        is_prime[j] = false;    // j contain prime i as a factor thus not a prime
                  }
            }
      }
      for (i = 2; i <= n; ++i) {
            if (is_prime[i] && i % 4 == 1) primes.push_back(i);
      }
      return primes;
}

int
main(int argc, char** argv)
{
    ul maxn = 1e7;
    const ul mod = 1e18;
    if (argc > 1) {
        sscanf(argv[1], "%lu", &maxn);
    }
    ul bound{static_cast<ul>(sqrt(maxn*maxn*4+1))};
    ul res = 0;
    auto primes{findPrimes(bound)};
    auto begin = primes.begin();
    auto end = primes.end();
    vector<vector<ul>> notPossible(maxn+1, vector<ul>{});
    for (auto &p: primes) {
        auto x = Toolbox<ul>::tonelliShanks(p-1, p);
        if (x % 2) x = p-x;
        assert((x*x+1)%p==0);
        for (ul i = p+x/2; i <= maxn; i += p) {
            notPossible[i].push_back(p);
        }
        if (p >= x/2) {
            for (ul i = p-x/2; i <= maxn; i += p) {
                notPossible[i].push_back(p);
            }
        }
    }
    for (ul i = 1; i <= maxn; ++i) {
        ul ub{i*i*4+1};
        if (notPossible[i].size() > 0) {
            ul maxp = 0;
            for (auto &p: notPossible[i]) {
                maxp = max(maxp, p);
                while (ub % p == 0) {
                    ub /= p;
                }
            }
            maxp = max(maxp, ub);
            // cout << "maxp = " << maxp << endl;
            res = (res + maxp) % mod;
        } else {
            res = (res + ub) % mod;
        }
    }
    cout << res << endl;
}
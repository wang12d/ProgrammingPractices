/*
 * @Author: Heng
 * @Created Date: 2022-03-27
 */

#include <bits/stdc++.h>
#include "Toolbox.h"


using namespace std;
using ull = __int128_t;
using tull = Toolbox<ull>;

unordered_map<ull, unordered_map<ull, ull>> cache;
vector<ull> primes(tull::findPrimes(static_cast<ull>(1e8)));
vector<vector<ull>> smallPrimes;
const ull M{static_cast<ull>(1e9+7)};


ull
root(ull x, ull r)
{
    ull lo{1}, hi{static_cast<ull>(floor(pow(static_cast<double>(x), 1.0/static_cast<double>(r))))+100};

    ull ans{1};
    while (hi >= lo) {
        ull mid{lo+((hi-lo)>>1)};
        if (tull::power(mid, r) <= x) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

ull
phi(ull x, ull a)
{
    if (cache[x].find(a) != cache[x].end()) {
        return cache[x][a];
    }

    if (a == 1) {
        return (x+1) >> 1;
    }

    ull t{phi(x, a-1) - phi(x / primes.at(a-1), a-1)};

    return cache[x][a] = t;
}

ull
pi(ull x)
{
    if (x <= primes.back()) {
        return upper_bound(begin(primes), end(primes), x) - begin(primes);
    }

    ull a{pi(root(x, 4))};
    ull b{pi(root(x, 2))};
    ull c{pi(root(x, 3))};

    ull s{phi(x, a) + (((b+a-2)*(b-a+1)) >> 1)};

    for (ull i{a+1}; i <= b; ++i) {
        ull w{x / primes.at(i-1)};

        ull lim = pi(root(w, 2));

        s = s - pi(w);

        if (i <= c) {
            for (ull j{i}; j <= lim; ++j) {
                s = s - pi(w / primes.at(j-1)) + j -1;
            }
        }
    }

    return s;
}

int
main(int argc, char** argv)
{
    tull::timer();

    ull n{static_cast<ull>(1e12)};
    if (argc > 1) {
        sscanf(argv[1], "%llu", &n);
    }
    ull rootN{root(n, 2)};

    for (auto i{0}; i < primes.size(); ++i) {
        ull p{primes.at(i)};
        if (p > rootN) {
            break;
        }
        smallPrimes.emplace_back();
        ull mul{1}, nextm;
        while (mul <= n) {
            nextm = mul * p; 
            smallPrimes.back().emplace_back(
                n / mul - n / nextm
            );
            mul = nextm;
        }
    }

    ull ans{0};
    for (auto &v: smallPrimes) {
        ull x{0};
        for (ull i{0}; i < v.size(); ++i) {
            for (ull j{i+1}; j < v.size(); ++j) {
                {
                    ull a{2 * (j - i) % M};
                    ull b{v.at(i) * v.at(j) % M};
                    ull c{a * b % M};
                    x = (x + c) % M;
                }
            }
        }
        ans = (ans + x) % M;
    }

    vector<ull> piCache;
    for (ull i{1}; i < rootN-1; ++i) {
        piCache.emplace_back(pi(n/i)-pi(n/(i+1)));
    }
    piCache.emplace_back(pi(n/(rootN-1)) - pi(rootN));

    ull idx{1};
    for (auto& p: piCache) {
        {
            ull a{p * idx % M};
            ull b{2 * (n-idx) % M};
            ull c{a * b % M};

            ans = (ans + c) % M;
            idx++;
        }
    }

    cout << static_cast<long long>(ans) << endl;
    tull::timeCost();
}
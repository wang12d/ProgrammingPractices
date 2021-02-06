#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <assert.h>
#include "Toolbox.h"

using std::min;
using std::cout;
using std::endl;
using std::vector;
using std::next_permutation;
using std::map;

const unsigned long MOD = 1e16;
const unsigned long maxn = 3e3;
vector<vector<unsigned long>> dp(maxn, vector<unsigned long>(maxn, 0));

template<typename T> void
printVector(const vector<T>& vec)
{
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(std::cout, " "));
  cout << endl;
}

unsigned long
factorial(unsigned long n)
{
    unsigned long res = 1;
    for (unsigned long i = n; i >= 2; --i) {
        res = res * i;
    }
    return res;
}

unsigned long
fastMod(unsigned long base, unsigned long expt, unsigned long mod)
{
    unsigned long res = 1;
    while (expt) {
        if (expt & 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        expt >>= 1;
    }
    return res;
}

unsigned long 
pot(unsigned long n, unsigned long m)
{
    unsigned long res = 0;
    unsigned long p = m;
    while (n / p) {
        res += n / p;
        p *= m;
    }
    return res;
}

unsigned long
combinationMod(unsigned long n, unsigned long k, unsigned long mod, vector<int>& primes)
{
    if (dp[k][n]) return dp[k][n];
    if (k == 0 || n == k) return dp[k][n] = 1;
    unsigned long sz = primes.size();
    unsigned long res = 1;
    for (unsigned long i = 0; i < sz; ++i) {
        auto power = pot(n, primes[i]) - pot(n-k, primes[i]) - pot(k, primes[i]);
        res = res * fastMod(primes[i], power, mod) % mod;
    }
    return dp[k][n] = res;
}


unsigned long
getMultiples(vector<unsigned long>& vec)
{
    unsigned long sz = vec.size();
    unsigned long res = factorial(sz-1);
    unsigned long sum = 0;
    map<unsigned long,unsigned long> memo;
    for (auto &v: vec) {
        sum += v;
        memo[v]++;
    }
    for (auto &p: memo) {
        if (p.second == sz) {
            return p.first;
        }
        unsigned long f = factorial(p.second);
        assert(res % f == 0);
        res /= f;
    }
    return sum * res;
}

void // Get all DS digits
getAllDigits(unsigned long current, unsigned long remain, vector<unsigned long>& currVec, vector<vector<unsigned long>>& res)
{
    if (remain == 0) {
        res.push_back(currVec);
        return;
    }
    for (unsigned long i = min(remain, current); i >= 1; --i) {
        currVec.push_back(i);
        getAllDigits(i, remain-i, currVec, res);
        currVec.pop_back();
    }
}

void
getAllDS(int S)
{
    vector<unsigned long> currVec;
    vector<vector<unsigned long>> allDSs;
    auto primes{Toolbox<int>::findPrimes(S)};
    for (unsigned long i = 9; i >= 1; --i) {
        currVec.push_back(i);
        for (unsigned long j = i; j >= 1; --j) {
            currVec.push_back(j);
            getAllDigits(j, i-j, currVec, allDSs);
            currVec.pop_back();
        }
        currVec.pop_back();
    }
    __int128_t res = 0;
    for (auto &V: allDSs) {
        unsigned long sz = V.size();
        if (sz > S) continue;
        __int128_t tmp = 0;
        for (long j = S-1; j >= sz-1; --j) {
            vector<unsigned long> cnt(j+1, 0);
            tmp = (tmp + (static_cast<__int128_t>(fastMod(10, j, MOD)) * combinationMod(j, sz-1, MOD, primes) % MOD)) % MOD;
            for (long i = sz-2, c = 1; i >= 0; --i, ++c) {
                unsigned long prev = cnt[j-c]; cnt[j-c] = 1;
                for (long k = j-c; k >= i; --k) {
                    if (k != j-c) {
                        unsigned long tmpp = cnt[k];
                        cnt[k] = (prev+cnt[k+1])%MOD;
                        prev = tmpp;
                    }
                    __int128_t mul = static_cast<__int128_t>(fastMod(10, k, MOD)) * combinationMod(k, i, MOD, primes) % MOD;
                    tmp = (tmp + (mul * cnt[k] % MOD)) % MOD;
                }
            }
        }
        res = (res + tmp * getMultiples(V) % MOD) % MOD;
    }
    cout << static_cast<unsigned long>(res%MOD) << endl;
}

int
main(int argc, char** argv)
{
    int S;
    sscanf(argv[1], "%d", &S);
    getAllDS(S);
}
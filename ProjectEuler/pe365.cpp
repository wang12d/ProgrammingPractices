/*
 * @Author: WangHeng 
 * @Date: 2018-12-29 18:33:26 
 * @Last Modified by: WangHeng
 * @Last Modified time: 2018-12-29 19:07:39
 */


#include <iostream>
#include "Toolbox.h"
#include <vector>

using ul = long long int;
using std::cout;
using std::endl;
using std::vector;

const ul maxnp = 5000;
const ul n = 1e18;
const ul k = 1e9;
vector<ul> dp(maxnp);

ul combinationPrimeMod(const ul&, const ul&, const ul&);
ul hugeCombinationPrimeMod(const ul&, const ul&, const ul&);

int
main(int argc, char** argv)
{
    auto primes{Toolbox<ul>::findPrimes(5000)};
    vector<ul> primesRange;
    for (auto &p: primes) {
        if (p > 1000) primesRange.push_back(p);
    }
    auto sz = primesRange.size();
    for (auto &p: primesRange) {
        hugeCombinationPrimeMod(n, k, p);
    }
    ul res = 0;
    for (int i = sz-1; i >= 2; --i) {
        for (int j = i-1; j >= 1; --j) {
            for (int k = j-1; k >= 0; --k) {
                res = (res + Toolbox<ul>::CRT({
                    primesRange[i], primesRange[j], primesRange[k]
                }, {
                    dp[primesRange[i]], dp[primesRange[j]], dp[primesRange[k]]
                })); 
            }
        }
    }
    cout << res << endl;
}

ul // 由卢卡斯定理
hugeCombinationPrimeMod(const ul& n, const ul& k, const ul& mod)
{
    if (n < k) return 0;
    if (dp[mod]) return  dp[mod];
    ul res = 1;
    ul p{n}, kp{k};
    while (p) {
        res = (res * combinationPrimeMod(p%mod, kp%mod, mod)) % mod;
        p /= mod; kp /= mod;
    }
    return dp[mod] = res;
}

ul
combinationPrimeMod(const ul& n, const ul& k, const ul& mod)
{
    if (k > n) return 0;
    if (k == 0) return 1;
    ul res = 1 % mod;
    for (ul i = 2; i <= n; ++i) {
        res = (res * i) % mod;
    }
    ul rev = 1 % mod;
    for (ul i = 2; i <= k; ++i) {
        rev = (rev * i) % mod;
    }
    for (ul i = 2; i <= n-k; ++i) {
        rev = (rev * i) % mod;
    }
    ul a, b; Toolbox<ul>::extendGCD(rev, mod, &a, &b);
    while (a < 0) a += mod;
    return (res * a) % mod;
}
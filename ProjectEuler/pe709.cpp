#include <bits/stdc++.h>
#include "Toolbox.h"

using std::cout;
using std::endl;
using std::vector;
using std::accumulate;
using std::pair;
using std::unordered_map;
using ul = unsigned long;

const ul MOD = 1020202009;
const ul shilt = 1e5;

void
fastCombinationMod(vector<vector<ul>>& comb, ul mod)
{
    int sz = comb.size();
    comb[0][0] = 1;
    comb[1][0] = comb[1][1] = 1;
    for (int i = 2; i < sz; ++i) {
        comb[i][0] = comb[i][i] = 1;
        for (int k = 1; k < i; ++k) {
            comb[i][k] = (comb[i-1][k-1] + comb[i-1][k]) % mod;
        }
    }
}

int
main(int argc, char** argv)
{
    ul maxn = 24680+1;
    vector<ul> dp(maxn+1, 0);
    dp[0] = dp[1] = 1;
    ul maxnn;
    if (argc > 1) {
        sscanf(argv[1], "%lu", &maxnn);
    } else {
        maxnn = maxn-1;
    }
    vector<vector<ul>> comb(maxnn, vector<ul>(maxnn, 0));
    fastCombinationMod(comb, MOD);
    auto primes{Toolbox<int>::findPrimes(maxn+1)};
    long rev, tmp; Toolbox<long>::extendGCD(2, MOD, &rev, &tmp);
    rev = (rev + MOD) % MOD;
    for (int i = 1; i < maxnn; ++i) {
        for (int k = i; k >= 0; k--) {
            dp[i+1] += (dp[k] * dp[i-k] % MOD) * comb[i][k] % MOD;
            dp[i+1] %= MOD;
        }
        dp[i+1] = (dp[i+1] * rev) % MOD;
    }
    cout << dp[maxnn] << endl;
}
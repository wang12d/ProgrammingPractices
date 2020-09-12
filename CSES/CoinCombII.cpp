#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int
main(int argc, char** argv)
{
    static const int MOD = 1e9 + 7;
    static const int maxx = 1e6 + 1;
    static const int maxn = 100;
    vector<ll> dp(maxx, 0);
    vector<int> coins(maxn, 0);
    int n,x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> coins[i];
    sort(coins.begin(), coins.begin()+n);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        int cv = coins[i];
        for (int j = cv; j <= x; ++j) {
            dp[j] = (dp[j] + dp[j-cv]) % MOD;
        }
    }
    cout << dp[x] << endl;
}
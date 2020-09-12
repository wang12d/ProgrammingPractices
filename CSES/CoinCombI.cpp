#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int
main(int argc, char** argv)
{
    static const int maxx = 1e6 + 1;
    static const int maxn = 100;
    static const int MOD = 1e9+7;
    int n, x;
    cin >> n >> x;
    vector<ll> dp(maxx, 0);
    vector<int> coins(maxn, 0);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    dp[0] = 1;
    sort(coins.begin(), coins.begin()+n);
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            int cv = coins[j];
            if (cv > i) break;
            dp[i] = (dp[i] + dp[i-cv]) % MOD;
        }
    }
    cout << dp[x] << endl;
}
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
int
main(int argc, char** argv)
{
    static const int maxn = 1e6+1;
    static const int MOD = 1e9+7;
    vector<ll> dp(maxn, 0);
    dp[0] = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(6, i); ++j) {
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }
    cout << dp[n] << endl;
}
#include <bits/stdc++.h>

using namespace std;

int
main(int argc, char** argv)
{
    static const int MOD = 1e9+9;
    static const int maxn = 1e6+1;
    vector<int> dp(maxn, 0);
    dp[0] = 1; dp[2] = 1; dp[3] = 1;
    int T, n;
    for (int i = 4; i <= maxn; ++i) {
        dp[i] = (dp[i-2] + dp[i-3]) % MOD;
    }
    cin >> T;
    while (T--) {
        cin >> n;
        cout << dp[n] % MOD << endl;
    }
}
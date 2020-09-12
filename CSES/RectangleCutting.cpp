#include <bits/stdc++.h>

using namespace std;

int
main(int argc, char** argv)
{
    static const int maxn = 500;
    vector<vector<int>> dp(maxn+1, vector<int>(maxn+1, INT_MAX));
    for (int i = 1; i <= maxn; ++i) dp[i][i] = 0;
    int n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= m; ++j) {
            for (int k = 1; k < j; ++k) {
                dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[i][j-k]);
            }
            for (int k = 1; k < i; ++k) {
                dp[i][j] = min(dp[i][j], 1+dp[k][j]+dp[i-k][j]);
            }
            dp[j][i] = dp[i][j];
        }
    }
    cout << dp[n][m] << endl;
}
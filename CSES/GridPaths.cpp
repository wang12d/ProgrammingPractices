#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int
main(int argc, char** argv)
{
    static const int maxn = 1e3+1;
    static const int MOD = 1e9+7;
    vector<vector<char>> grids(maxn, vector<char>(maxn, '.'));
    vector<vector<ll>> dp(maxn, vector<ll>(maxn, 0));
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grids[i][j];
        }
    }
    dp[0][0] = grids[0][0] == '.';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grids[i][j] != '*') {
                if (i && j) {
                    dp[i][j] = (grids[i-1][j] != '*' ? dp[i-1][j] : 0) + (grids[i][j-1] != '*' ? dp[i][j-1] : 0);
                }
                else if (i) {
                    dp[i][j] = grids[i-1][j] != '*' ? dp[i-1][j] : 0;
                }
                else if (j) {
                    dp[i][j] = grids[i][j-1] != '*' ? dp[i][j-1] : 0;
                }
            }
            dp[i][j] = dp[i][j] % MOD;
        }
    }
    cout << dp[n-1][n-1] << endl;
}
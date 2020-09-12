#include <bits/stdc++.h>

using namespace std;

int
main(int argc, char** argv)
{
    static const int maxn = 1e6;
    static const int maxx = 1e6;
    static const int maxc = 100;
    vector<int> coins(maxc, 0);
    vector<int> dp(maxn+1, INT_MAX-2);
    dp[0] = 0;
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.begin()+n);
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            int cv = coins[j];
            if (cv > i) break;
            dp[i] = min(dp[i-cv]+1, dp[i]);
        }
    }
    cout << (dp[x] == INT_MAX -2? -1 : dp[x]) << endl;
}
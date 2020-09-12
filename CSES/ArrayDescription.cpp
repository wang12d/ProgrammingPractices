#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

static const int maxn = 1e5 + 1;
static const int maxm = 100;
static const int MOD = 1e9 + 7;

ll
search(int val, int ind, const int& m, const int& n, vector<int>& arr, vector<vector<ll>>& dp)
{
    if (ind == n) return 1;
    if (dp[val][ind] != -1) return dp[val][ind];
    if (arr[ind] != 0) {
        if (abs(arr[ind] - val) > 1)   return dp[val][ind] = 0;
        else return dp[val][ind] = search(arr[ind], ind+1, m, n, arr, dp) % MOD;
    }
    else {
        ll ans = 0;
        int lower = max(val-1, 1), upper = min(m, val+1);
        for (int i = lower; i <= upper; ++i) {
            ans = (search(i, ind+1, m, n, arr, dp)+ans) % MOD;
        }
        return dp[val][ind] = ans;
    }
}

int
main(int argc, char** argv)
{
    vector<vector<ll>> dp(maxm+1, vector<ll>(maxn, -1));
    int n,m; cin >> n >> m;
    vector<int> arr(maxn, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    if (arr[0] == 0) {
        ll ans = 0;
        for (int i = 1; i <= m; ++i) {
            ans = (ans + search(i, 1, m, n, arr, dp)) % MOD;
        }
        cout << ans << endl;
    }
    else {
        cout << search(arr[0], 1, m, n, arr, dp) % MOD << endl;
    }
}
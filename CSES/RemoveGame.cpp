#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int
main(int argc, char** argv)
{
    static const int maxn = 5e3;
    vector<ll> acc(maxn+1, 0);
    vector<int> nums(maxn, 0);
    vector<vector<ll>> dp(maxn, vector<ll>(maxn, INT_MIN));
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i]; dp[i][i] = nums[i];
        acc[i+1] = acc[i] + nums[i];
    }
    for (int i = n-1; i >= 0; --i) {
        for (int j = i+1; j < n; ++j) {
            dp[i][j] = max(nums[i]+acc[j+1]-acc[i+1]-dp[i+1][j], nums[j]+acc[j]-acc[i]-dp[i][j-1]);
        }
    }
    cout << dp[0][n-1] << endl;
}
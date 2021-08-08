#include <bits/stdc++.h>

using namespace std;

static const int maxn = 1e5;
using ll = long long;

int 
main(int argc, char** argv)
{
    int t, n;
    cin >> t;
    vector<ll> dp(maxn, 0);
    vector<ll> arr(maxn, 0);
    vector<ll> min_val(maxn, 0);
    vector<int> dp_len(maxn, 0);
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        dp[0] = arr[0]; min_val[0] = arr[0];
        dp_len[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (dp[i-1] >= 0) {
                dp[i] = dp[i-1] + arr[i];
                min_val[i] = min(min_val[i-1], arr[i]);
                dp_len[i] = dp_len[i-1]+1;
            }
            else {
                dp[i] = arr[i];
                dp_len[i] = 1;
                min_val[i] = arr[i];
            }
        }
        ll maxv = *max_element(dp.begin(), dp.begin()+n);
        ll ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == maxv) {
                if (dp_len[i] > 1) {
                    ans = max(maxv, max(ans, maxv-min_val[i]));
                }
                else {
                    ans = max(ans, maxv);
                }
            }
        }
        cout << ans << endl;
    }
}
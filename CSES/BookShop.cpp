#include <bits/stdc++.h>

using namespace std;

int
main(int argc, char** argv)
{
    static const int maxx = 1e5 + 1;
    static const int maxn = 1e3;
    vector<int> dp(maxx, 0);
    vector<int> prices(maxn, 0);
    vector<int> pages(maxn, 0);
    int n, x; cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> pages[i];
    }
    int total_prices = accumulate(prices.begin(), prices.begin()+n, 0);
    if (total_prices <= x) {
        cout << accumulate(pages.begin(), pages.begin()+n, 0) << endl;
    }
    else {
        for (int i = prices[0]; i <= x; ++i) dp[i] = pages[0];
        for (int i = 1; i < n; ++i) {
            for (int j = x; j >= 1; --j) {
                if (j >= prices[i]) {
                    dp[j] = max(dp[j], dp[j-prices[i]]+pages[i]);
                }
            }
        }
        cout << dp[x] << endl;
    }
}
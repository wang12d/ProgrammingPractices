#include <bits/stdc++.h>

using namespace std;

int
main(int argc, char** argv)
{
    static const int maxn = 1e6+1;
    vector<int> dp(maxn, INT_MAX);
    int n; cin >> n;
    dp[0] = 0;
    for (int i = 1; i < 10; ++i) dp[i] = 1;
    for (int i = 10; i <= n; ++i) {
        int m = i; vector<int> digits;
        while (m) {
            int rem = m % 10;
            m /= 10;
            if (rem) {
                digits.push_back(rem);
            }
        }
        for (auto &d: digits) {
            dp[i] = min(dp[i], dp[i-d]+1);
        }
    }
    cout << dp[n] << endl;
}
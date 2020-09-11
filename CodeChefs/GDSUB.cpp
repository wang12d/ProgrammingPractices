#include <bits/stdc++.h>

using namespace std;

using ll=long long;

int
main(int argc, char** argv)
{
    static const int mod = 1e9+7;
    unordered_map<int, int> unique_nums;
    int N, K, num;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        unique_nums[num]++;
    }
    int sz = unique_nums.size();
    int number_of_loops = min(sz, K);
    auto end = unique_nums.end();
    int length = 1; vector<ll> dp(number_of_loops+1, 0);
    ll res = 0; dp[0] = 1;
    for (auto it = unique_nums.begin(); it != end; ++it) {
        vector<ll> tmp = dp;
        dp[1] = (tmp[1] + it->second) % mod;
        int last = min(length, number_of_loops);
        int i = 2;
        for (; i < last; ++i) {
            dp[i] = ((tmp[i-1] * it->second % mod) + tmp[i]) % mod;
        }
        if (i == length) {
            dp[last] = tmp[last-1] * it->second % mod;
        }
        else {
            dp[last] = ((tmp[last-1] * it->second % mod) + tmp[last]) % mod;
        }
        ++length;
    }
    for (auto &n: dp) {
        res = (res + n) % mod;
    }
    cout << res << endl;
}
#include <bits/stdc++.h>

using namespace std;

using ll=long long;
template<typename T>
T gcd(T a, T b)
{
    if (b == 0) return a;
    return gcd(b, a%b);
}

ll
search(int index, int g, vector<int>& vec, vector<vector<ll>>& dp, const int& N, int number_used)
{
    if (index == N) {
        return g == 1 && number_used > 1;
    }
    if (dp[index][g] >= 0)  return dp[index][g];
    ll ans = search(index+1, g, vec, dp, N, number_used) + search(index+1, gcd(g, vec[index]), vec, dp, N, number_used+1);
    return dp[index][g] = ans;
}

int
main(int argc, char** argv) 
{
    static const int maxn = 60;
    int T, N;
    cin >> T;
    vector<int> nums(maxn, 0);
    while (T--) {
        cin >> N; int maxv = -1;
        for (int i = 0; i < N; ++i) {
            cin >> nums[i];
            maxv = max(nums[i], maxv);
        }
        vector<vector<ll>> dp(N, vector<ll>(maxv+1, -1));
        ll ans = 0;
        for (int i = 0; i < N; ++i) {
            ans += search(i+1, nums[i], nums, dp, N, 1);
        }
        cout << ans << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll
binFind(int lo, int hi, int val, vector<vector<ll>>& vec)
{
    int prev = -1;
    while (hi > lo) {
        int mid = lo + (hi-lo) / 2;
        if (prev == mid) mid++;
        if (vec[mid][1] < val) lo = mid;
        else hi = mid-1;
        prev = mid;
    }
    return vec[lo][1] < val ? lo : -1;
}

int
main(int argc, char** argv)
{
    static const int maxn = 2e5;
    vector<vector<ll>> task(maxn, vector<ll>(3, 0));
    vector<ll> dp(maxn, 0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> task[i][0] >> task[i][1] >> task[i][2];
    }
    sort(task.begin(), task.begin()+n, [](const vector<ll>&a, const vector<ll>&b)->bool {
        if (a[1] == b[1])   return a[0] < b[0];
        else    return a[1] < b[1];
    });
    dp[0] = task[0][2];
    for (int i = 1; i < n; ++i) {
        int p = binFind(0, i-1, task[i][0], task);
        if (p == -1) {
            dp[i] = max(dp[i-1], static_cast<ll>(task[i][2]));
        }
        else {
            dp[i] = max(dp[i-1], dp[p] + task[i][2]);
        }
    }
    cout << dp[n-1] << endl;
}
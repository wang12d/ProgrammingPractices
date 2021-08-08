#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static const int maxl = 52;
static const int maxn = 52;
static const int maxs = 1e5;
static const int maxp = 26*53;

int
main(int argc, char** argv)
{
    int T, L, S;
    cin >> T;
    unordered_map<int, unordered_map<int, ll>> dp;
    for (int i = 1; i <= maxn; ++i) {
        unordered_map<int, unordered_map<int, ll>> tmp = dp;
        for (auto &it: tmp) {
            for (auto len: it.second) {
                dp[it.first+i][len.first+1] += len.second;
            }
        }
        dp[i][1]++;
    }
    for (int i = 1; i <= T; ++i) {
        cin >> L >> S;
        if (L > maxl || S > maxp) {
            cout << "Case " << i << ':' << ' ' << 0 << endl;
            continue;
        }
        cout << "Case " << i << ':' << ' ' << dp[S][L]<< endl;
    }
}
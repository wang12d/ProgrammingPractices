#include <bits/stdc++.h>
#include "Toolbox.h"


using namespace std;
using ll = long long;
using tll = Toolbox<ll>;
using biv = vector<vector<ll>>;


static const ll maxn{60}, maxm{40};
vector<vector<biv>> dp(maxn+1, vector<biv>(maxm+1, biv(maxn+1, vector<ll>(maxm+1, -1))));


ll
dfs(ll n, ll m, ll a, ll b)
{
    if (a > n || b > m) {
        return 0;
    }
    ll& ans{dp[n][m][a][b]};
    if (ans >= 0) {
        return ans;
    }
    if (a == 0 && b == 0) {
        return 0;
    }
    ans = 0;
    for (ll i{a}; i >= 0; --i) {
        for (ll j{i == a ? b : m}; j >= 0; --j) {
            ans += dfs(n-a, m-b, i, j);
        }
    }
    return ans;
}


int
main(int argc, char** argv)
{
    tll::timer();
    dp[0][0][0][0] = 1;
    ll ans{0};
    for (ll i{1}; i <= maxn; ++i) {
        for (ll j{0}; j <= maxm; ++j) {
            ll tmp{dfs(maxn, maxm, i, j)};
            ans += tmp;
        }
    }
    cout << ans << endl;
    tll::timeCost();
}
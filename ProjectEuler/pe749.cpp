#include <bits/stdc++.h>
#include "Toolbox.h"


using namespace std;
using ll = long long;
using tll = Toolbox<ll>;

const ll MAXN{static_cast<ll>(1e16)};
const ll MAXD{10}; const ll MAXM{16};
vector<ll> digitPower;


void
combinationWithRepetition(ll idx, ll k, vector<ll>& comb, vector<vector<ll>>& all_combs)
{
    if (k == 0) {
        all_combs.emplace_back(comb);
    } else {
        for (ll i{idx}; i < MAXD; ++i) {
            comb.emplace_back(i);
            combinationWithRepetition(i, k-1, comb, all_combs);
            comb.pop_back();
        }
    }
}

bool
check(vector<ll>& digits, ll val)
{
    vector<int> isExist(MAXD, 0);
    for (ll i{0}; i < digits.size(); ++i) {
        isExist.at(val % 10)++;
        val /= 10;
    }
    if (val != 0) {
        return false;
    }
    for (auto& d: digits) {
        isExist.at(d)--;
    }
    for (auto& d: isExist) {
        if (d != 0) {
            return false;
        }
    }
    return true;
}

ll
nearPowerSum(vector<ll>& digits, ll maxn)
{
    ll sum{0}, prev{-1};
    ll p{0};
    while (sum <= maxn && sum-prev > 0) {
        ll idx{0};
        for (auto& d: digits) {
            digitPower.at(idx++) *= d;
        }
        ++p; prev = sum;
        sum = accumulate(begin(digitPower), end(digitPower), 0LL);
        if (sum < 0) {
            break;
        }
        if (check(digits, sum+1)) {
            return sum+1;
        }
        if (sum && check(digits, sum-1)) {
            return sum-1;
        }
    }
    return 0;
}

int
main(int argc, char** argv)
{
    tll::timer();

    vector<vector<ll>> all_combs;
    vector<ll> comb;
    ll m{MAXM}, maxn{MAXN};
    if (argc > 1) {
        sscanf(argv[1], "%llu", &m);
        maxn = 1LL;
        for (ll i{0}; i < m; ++i) {
            maxn *= 10LL;
        }
    }
    digitPower.resize(m, 1);
    ll ans{0};
    combinationWithRepetition(0, m, comb, all_combs);
    for (auto& comb: all_combs) {
        assert(comb.size() == digitPower.size());
        fill(begin(digitPower), end(digitPower), 1);
        ans += nearPowerSum(comb, maxn);
    }
    cout << ans << endl;

    tll::timeCost();
}
#include <bits/stdc++.h>
#include "Toolbox.h"


using namespace std;
using ll = long long;
using tll = Toolbox<ll>;

const ll MOD{static_cast<ll>(1e9+7)};
const ll MAXK{static_cast<ll>(1e8)};
const ll MAXN{static_cast<ll>(1e16)};
vector<ll> factorials(MAXK+1, 1);


int
main(int argc, char** argv)
{
    tll::timer();
    long long n{MAXN}, k{MAXK};
    if (argc > 2) {
        sscanf(argv[1], "%lld", &k);
        sscanf(argv[2], "%lld", &n);
    }

    for (ll i{1}; i <= MAXK; ++i) {
        factorials.at(i) = (factorials.at(i-1) * i) % MOD;
    }
    ll ans{0};
    for (ll i{0}; i <= (k >> 1); ++i) {
        ll expt{(k-2*i)*(n/k)}; ll expt_mod{tll::powerWithMOD(2, expt, MOD)};
        ll b{(((factorials.at(k-i)*factorials.at(k-2*i))%MOD)*((factorials.at(i)*factorials.at(i))%MOD))%MOD};
        ll inv_b, tmp;
        tll::extendGCD(b, MOD, &inv_b, &tmp);
        while (inv_b < 0) {
            inv_b += MOD;
        }
        ll numerator{(factorials.at(k)*factorials.at(k-i))%MOD};
        ans += (inv_b*numerator%MOD)*expt_mod%MOD;
    }
    cout << ans%MOD << endl;
    tll::timeCost();
}
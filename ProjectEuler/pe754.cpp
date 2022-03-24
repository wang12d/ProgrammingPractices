#include <bits/stdc++.h>
#include "Toolbox.h"

using namespace std;
using ll = long long;
using tll = Toolbox<ll>;

const ll MOD{static_cast<ll>(1e9+7)};
const ll MAXN{static_cast<ll>(1e8)};
vector<ll> factorials;
vector<vector<ll>> prime_factor;


void
comb_prod(ll idx, ll n, ll k, ll val, vector<ll>& items, vector<ll>& prods)
{
    if (k == 0) {
        prods.push_back(val);
    } else {
        for (ll i{idx}; i < n; ++i) {
            val *= items.at(i);
            comb_prod(i+1, n, k-1, val, items, prods);
            val /= items.at(i);
        }
    }
}

int
main(int argc, char** argv)
{
    tll::timer();
    ll n{MAXN};
    if (argc > 1) {
        sscanf(argv[1], "%lld", &n);
    }

    factorials.resize(n+1, 1);
    prime_factor.resize(n+1, {});
    ll ans{1};
    for (ll i{2}; i <= n; ++i) {
        factorials.at(i) = factorials.at(i-1) * i % MOD;
        ans = ans * factorials.at(i) % MOD;
    }

    auto primes{tll::findPrimes(n)};
    for (ll i{0}; i < primes.size(); ++i) {
        ll p{primes.at(i)};
        for (ll i{p}; i <= n; i += p) {
            prime_factor.at(i).emplace_back(p);
        }
    }

    vector<ll> prods;
    for (ll i{1}; i <= n; ++i) {
        ll expt{0};
        for (ll k{1}; k <= prime_factor.at(i).size(); ++k) {
            comb_prod(0, prime_factor.at(i).size(), k, 1, prime_factor.at(i), prods);
            for (auto& p: prods) {
                if (k & 1) {
                    expt += (n/p-i/p+1);
                } else {
                    expt -= (n/p-i/p+1);
                }
            }
            prods.clear();
        }
        ll val{tll::powerWithMOD(i, expt, MOD)};
        ll inv_val, tmp;
        tll::extendGCD(val, MOD, &inv_val, &tmp);
        ans = ans * inv_val % MOD;
    }

    cout << (ans+MOD)%MOD << endl;
    tll::timeCost();
}
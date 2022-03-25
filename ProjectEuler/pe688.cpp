#include <bits/stdc++.h>
#include "Toolbox.h"


using namespace std;
using ull = unsigned long long;
using ll = long long;
using tll = Toolbox<ll>;
using tll = Toolbox<ll>;

const ll MAXN{static_cast<ll>(1e16)};
const ll MOD{static_cast<ll>(1e9+7)};
ll TWOINV;


ll
accumulateSeq(ll init, ll length)
{

    return (length*(init+init+length-1) % MOD) * TWOINV % MOD;
}

ll
divAccuSeq(ll n, ll p)
{
    ll items{(n/p)%MOD};
    ll ans{p*accumulateSeq(1ll, items-1)%MOD};
    ans = (ans + ((n%p)+1)*items % MOD)%MOD;
    return ans;
}


int
main(int argc, char** argv)
{
    tll::timer();

    ll tmp;
    tll::extendGCD(2, MOD, &TWOINV, &tmp);
    while (TWOINV < 0) {
        TWOINV += MOD;
    }

    ll n{MAXN};
    if (argc > 1) {
        sscanf(argv[1], "%llu", &n);
    }

    ll acc{0}; ll upperBound{1};
    for (;acc <= n; ++upperBound) {
        acc += upperBound;
    }
    upperBound--;
    ll ans{0};

    for (ll l{1}; l <= upperBound; ++l) {
        ll k{l>>1}; ll minn{(l*l+l)/2-1};
        if (minn > n) {
            break;
        }

        if (l & 1) {
            ans = (ans + ((divAccuSeq(n, l) - (((n-minn)%MOD)*k%MOD))%MOD) - divAccuSeq(minn, l))%MOD;
        } else {
            ans = (ans + ((divAccuSeq(n+k, l) - (((n-minn)%MOD)*k%MOD))%MOD) - divAccuSeq(minn+k, l))%MOD;
        }
    }

    cout << static_cast<long long>((ans+MOD)%MOD) << endl;
    tll::timeCost();
}

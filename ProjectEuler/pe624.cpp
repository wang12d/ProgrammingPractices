/*
 * @Author: Heng
 * @Created Date: 2022-03-26
 */

#include <bits/stdc++.h>
#include "Toolbox.h"


using namespace std;
using ll = long long;
using tll = Toolbox<ll>;

const ll MP{static_cast<ll>(1e9+9)};
const ll TWO{2};

ll
fib(ll n, ll P)
{
    ll p{n-1};

    vector<vector<ll>> base{{1, 1}, {1, 0}};
    vector<vector<ll>> ans{{1, 0}, {0, 1}};
    vector<vector<ll>> tmp{{0, 0}, {0, 0}};
    while (p) {
        if (p & 1) {
            tmp.at(0).at(0) = ((base.at(0).at(0) * ans.at(0).at(0) % P) + (base.at(0).at(1) * ans.at(1).at(0) % P)) % P;
            tmp.at(0).at(1) = ((base.at(0).at(0) * ans.at(0).at(1) % P) + (base.at(0).at(1) * ans.at(1).at(1) % P)) % P;
            tmp.at(1).at(0) = ((base.at(1).at(0) * ans.at(0).at(0) % P) + (base.at(1).at(1) * ans.at(1).at(0) % P)) % P;
            tmp.at(1).at(1) = ((base.at(1).at(0) * ans.at(0).at(1) % P) + (base.at(1).at(1) * ans.at(1).at(1) % P)) % P;

            for (auto i{0}; i < tmp.size(); ++i) {
                for (auto j{0}; j < tmp.front().size(); ++j) {
                    ans.at(i).at(j) = tmp.at(i).at(j);
                }
            }
        }

        tmp.at(0).at(0) = ((base.at(0).at(0) * base.at(0).at(0) % P) + (base.at(0).at(1) * base.at(1).at(0) % P)) % P;
        tmp.at(0).at(1) = ((base.at(0).at(0) * base.at(0).at(1) % P) + (base.at(0).at(1) * base.at(1).at(1) % P)) % P;
        tmp.at(1).at(0) = ((base.at(1).at(0) * base.at(0).at(0) % P) + (base.at(1).at(1) * base.at(1).at(0) % P)) % P;
        tmp.at(1).at(1) = ((base.at(1).at(0) * base.at(0).at(1) % P) + (base.at(1).at(1) * base.at(1).at(1) % P)) % P;

        for (auto i{0}; i < tmp.size(); ++i) {
            for (auto j{0}; j < tmp.front().size(); ++j) {
                base.at(i).at(j) = tmp.at(i).at(j);
            }
        }
        p >>= 1;
    }
    return ans.at(0).at(0);
}

int
main(int argc, char** argv)
{
    tll::timer();

    ll t{static_cast<ll>(1e18)};
    ll P{MP};

    if (argc > 2) {
        sscanf(argv[1], "%llu", &t);
        sscanf(argv[2], "%llu", &P);
    }
    
    ll fibval{fib(t, P)};

    ll b;
    {
        ll tmpa{tll::powerWithMOD(TWO*TWO, t, P) * fibval % P};
        ll tmpb{tll::powerWithMOD(TWO, t, P) * fib(t<<1, P) % P};
        ll tmpc{(((t&1) ? -1 : 1) * fibval) % P};

        b = ((tmpa + P - tmpb)%P + tmpc) % P;
    };

    while (b < 0) {
        b += P;
    }

    ll a;
    {
        ll tmpa{(tll::powerWithMOD(TWO, t, P) * fibval % P) * fib(t-1, P) % P};
        ll tmpb{((t&1) ? 1: -1) * fibval % P};

        a = (tmpa + tmpb) % P;
    };

    ll inv_b, tmp;
    tll::extendGCD(b, P, &inv_b, &tmp);

    while (inv_b < 0) {
        inv_b += P;
    }

    inv_b %= P;

    assert(((inv_b*b)%P)==1);
    ll ans{(inv_b * a) % P};

    cout << static_cast<ll>(ans) << endl;

    tll::timeCost();
}
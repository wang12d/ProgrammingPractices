#include <bits/stdc++.h>
#include "Toolbox.h"

using namespace std;

int
main(int argc, char** argv)
{
    using ll = long long;
    using tll = Toolbox<ll>;

    tll::timer();

    ll n{static_cast<ll>(1e16)};
    if (argc > 1) {
        sscanf(argv[1], "%lld", &n);
    }
    ll maxp{63};
    ll ans{0};
    for (ll p{1}; p <= maxp; ++p) {
        ll pp{1ll << p};
        ans += max(0ll,(n-pp+1)-(max(0ll, n-pp+1)/pp));
    }

    cout << ans << endl;
    tll::timeCost();
}
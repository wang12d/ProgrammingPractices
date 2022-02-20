#include <bits/stdc++.h>
#include "Toolbox.h"

using namespace std;

int
main(int argc, char** argv)
{
    using ull = unsigned long long;
    using tll = Toolbox<ull>;
    ull mod{static_cast<ull>(1e9+7)};
    ull maxsq{static_cast<ull>(1e14)};
    unordered_map<ull, ull> dp;

    function<ull(ull)> dfs = [&dfs, &dp](const ull& n)->ull {
        if (n <=  1) {
            return 1;
        }
        if (dp.find(n) != end(dp)) {
            return dp.at(n);
        }
        ull ans{0};
        for (ull i{2}; i*i <= n; ++i) {
            ans += dfs(n/(i*i));
        }
        return dp[n]=n-ans;
    };

    tll::timer();
    if (argc > 1) {
        sscanf(argv[1], "%llu", &maxsq);
    }

    ull maxq{static_cast<ull>(sqrt(maxsq))};
    vector<ull> primes{tll::findPrimes(maxq)};
    vector<ull> sqs(maxq+1);
    for (ull i{1}; i <= maxq; ++i) {
        sqs.at(i) = i*i;
    }

    ull remaining{maxsq};
    ull ans{0};
    for (ull i{2}; i <= maxq; ++i) {
        ull sq{sqs.at(i)}; ull s{maxsq/sq}; ull maxs{s};
        ull square_free{dfs(s)};
        ans = (ans+sq*square_free) % mod;
        remaining -= square_free;

    }
    ans = (ans + remaining) % mod;
    printf("%llu\n", ans);
    tll::timeCost();
}
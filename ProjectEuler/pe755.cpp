#include <bits/stdc++.h>
#include "Toolbox.h"

using namespace std;
using ull = unsigned long long;
using tll = Toolbox<ull>;

const ull MAXN{static_cast<ull>(1e13)};
vector<ull> fibs, prefix_sum;

void
init(ull n)
{
    ull a{1}, b{1};
    ull tmp; fibs.emplace_back(0);
    while (b <= n) {
        fibs.emplace_back(b);
        tmp = b; b = a+b; a = tmp;
    }
    prefix_sum.resize(fibs.size());
    for (auto i{1}; i < fibs.size(); ++i)  {
        prefix_sum.at(i) = prefix_sum.at(i-1)+fibs.at(i);
    }
}

ull
solve(ull n, ull idx)
{
    ull ans{0};
    for (ull i{idx}; ; --i) {
        if (n >= prefix_sum.at(i)) {
            ans += (1ull << i);
            break;
        }
        if (n >= fibs.at(i)) {
            ans += solve(n-fibs.at(i), i-1);
        }
        if (i == 0) break;
    }
    return ans;
}

int
main(int argc, char** argv)
{
    tll::timer();
    ull N{MAXN};
    if (argc > 1) {
        sscanf(argv[1], "%llu", &N);
    }
    init(N);
    cout << solve(N, fibs.size()-1) << endl;
    tll::timeCost();
}
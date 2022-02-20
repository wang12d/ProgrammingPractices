#include <bits/stdc++.h>
#include "Toolbox.h"

using namespace std;



int
main(int argc, char** argv)
{
    using ill = long long;
    using tll = Toolbox<ill>;

    tll::timer();
    ill maxn{static_cast<ill>(1e6)};
    ill maxx{static_cast<ill>(1e4)}, maxy{static_cast<ill>(1e4)};
    ill MOD{static_cast<ill>(1e9+7)};

    sscanf(argv[1], "%llu", &maxx);
    sscanf(argv[2], "%llu", &maxy);
    unordered_set<ill> is_fibs;
    ill a{1}, b{1}, c;
    while (b <= maxn) {
        is_fibs.insert(b*b);
        c = b; b = a + b; a = c;
    }
    
    vector<pair<ill,ill>> valid_pairs{};
    auto fibs_end{end(is_fibs)};
    for (ill i{0}; i <= maxx; ++i) {
        ill i_sq{i*i};
        for (ill j{0}; j <= maxy; ++j) {
            ill j_sq{j*j};
            if (is_fibs.find(i_sq+j_sq) != fibs_end) {
                valid_pairs.emplace_back(i, j);
            }
        }
    }

    sort(begin(valid_pairs), end(valid_pairs), [](const auto& a,  const auto& b) {
        return a.second < b.second;
    });

    vector<vector<ill>> dp(maxx+1, vector<ill>(maxy+1));
    for_each(begin(dp), end(dp), [](auto& v) {
        fill(begin(v), end(v), 0);
    });
    dp.front().front() = 1;

    for (ill i{0}; i <= maxx; ++i) {
        for (ill j{i}; j <= maxy; ++j) {
            for (auto& p: valid_pairs) {
                if (p.second > j) break;
                if (p.first <= i && p.second <= j) {
                    dp.at(i).at(j) = (dp.at(i).at(j)+dp.at(i-p.first).at(j-p.second)) % MOD;
                }
            }
            dp.at(j).at(i) = dp.at(i).at(j);
        }
    }

    printf("%lld\n",dp.back().back());
    tll::timeCost();
}
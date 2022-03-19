#include <bits/stdc++.h>
#include "Toolbox.h"

using namespace std;
using ull = unsigned long long;
using tll = Toolbox<ull>;


char chs[]{'A', 'E', 'F', 'R'};
unordered_map<string, ull> to_idx;
unordered_map<ull, string> rev_idx;
unordered_map<string, ull> convert{
    {"FREE", 1},
    {"FARE", 2},
    {"AREA", 4},
    {"REEF", 8}
};

ull MAXD{4}, idx{0};
ull MAXL{30}, MAXV{256}, MAXS{16};
string s;
vector<vector<vector<ull>>> dp(
    MAXL+1, vector<vector<ull>>(
        MAXV, vector<ull>(
            MAXS, 0
        )
    )
);

void
generate_index(ull depth, ull& idx, string& s)
{
    if (depth == MAXD) {
        to_idx.emplace(s, idx);
        rev_idx.emplace(idx, s);
        idx++;
        return;
    }
    for (ull i{0}; i < strlen(chs); ++i) {
        s.push_back(chs[i]);
        generate_index(depth+1, idx, s);
        s.pop_back();
    }
}

int
main(int argc, char** argv)
{
    tll::timer();
    ull target_length{30};
    if (argc > 1) {
        sscanf(argv[1], "%llu", &target_length);
    }
    generate_index(0, idx, s);
    for (ull i{0}; i < MAXV; ++i) {
        dp.at(MAXD).at(i).at(convert[rev_idx.at(i)]) = 1;
    }
    for (ull l{4}; l < MAXL; ++l) {
        for (ull v{0}; v < MAXV; ++v) {
            string word{rev_idx.at(v).substr(1)};
            for (ull s{0}; s < MAXS; ++s) {
                if (dp.at(l).at(v).at(s) > 0) {
                    for (ull i{0}; i < MAXD; ++i) {
                        word.push_back(chs[i]);
                        ull ns{convert[word]};
                        if ((ns & s) == 0) {
                            dp.at(l+1).at(to_idx.at(word)).at((ns | s)) += dp.at(l).at(v).at(s);
                        }
                        word.pop_back();
                    }
                }
            }
        }
    }
    ull ans{0};
    for (ull v{0}; v < MAXV; ++v) {
        ans += dp.at(target_length).at(v).at(MAXS-1);
    }
    cout << ans << endl;
    tll::timeCost();
}
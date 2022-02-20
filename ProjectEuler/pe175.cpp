#include <bits/stdc++.h>
#include "Toolbox.h"

using namespace std;

int
main()
{
    using ull = unsigned long long;

    ull la{0}, lb{1}, ha{1}, hb{0};
    ull p{13}, q{17};
    vector<ull> ans{1};
    while (true) {
        ull ma{la+ha}, mb{lb+hb};
        ull x{ma*q}, y{mb*p};
        if (x > y) {
            ans.emplace_back(1);
            ha = ma; hb = mb;
        } else if (x < y) {
            ans.emplace_back(0);
            la = ma; lb = mb;
        } else {
            break;
        }
    }
    reverse(begin(ans)+1, end(ans));
    string output_ans; int cnt{0};
    int prev{-1};
    for (const auto& x: ans) {
        if (prev != x) {
            if (cnt) {
                output_ans.append(to_string(cnt));
                output_ans.push_back(',');
            }
            cnt = 1;
        } else {
            cnt++;
        }
        prev = x;
    }
    output_ans.append(to_string(cnt));
    cout << output_ans << endl;
}
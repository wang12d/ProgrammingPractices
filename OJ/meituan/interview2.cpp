#include <vector>
#include <algorithm>
#include <iostream>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

static const int MAXC{26};

int
main()
{
    string s; int n;
    cin >> s;
    cin >> n; int ptr{1};
    vector<vector<int>> chLoc(MAXC, vector<int>{});
    for (auto &x: s) {
       chLoc[x-'a'].push_back(ptr++); 
    }
    int op, c;
    char ch;
    for (int i{0}; i < n; ++i) {
        cin >> op;
        if (op == 1) {
            cin >> ch;
            chLoc[ch-'a'].push_back(ptr++);
        } else {
            cin >> c;
            int ind{s[c-1] - 'a'};
            auto it = std::lower_bound(chLoc[ind].begin(), chLoc[ind].end(), c);
            int ans = -1;
            if (it+1 != chLoc[ind].end()) {
                ans = *(it+1) - *it;
            }
            if (it != chLoc[ind].begin()) {
                if (ans < 0) {
                    ans = *it - *(it-1);
                } else {
                    ans = std::min(ans, static_cast<int>(*it-*(it-1)));
                }
            }
            cout << ans << endl;
        }
    }
}
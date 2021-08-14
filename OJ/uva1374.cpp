#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

bool
dfs(vector<int>& ans, int d, int maxd, int target)
{
    if (ans[d] == target) {
        return true;
    }
    if (d == maxd) {
        return false;
    }
    auto maxv{*std::max_element(ans.begin(), ans.begin()+d+1)};
    if ((maxv << (maxd-d)) < target) {
        return false;
    }
    for (int i{d}; i >= 0; --i) {
        ans[d+1] = ans[d] + ans[i];
        if (dfs(ans, d+1, maxd, target)) {
            return true;
        }
        ans[d+1] = ans[d] - ans[i];
        if (dfs(ans, d+1, maxd, target)) {
            return true;
        }
    }
    return false;
}

int
main(int argc, char** argv)
{
    int n;
    static const int maxn{1000000};
    vector<int> ans(maxn, 0);
    while (true) {
        cin >> n;
        if (!n) {
            break;
        }
        for (int i{0}; i <= n; ++i) {
            ans[0] = 1;
            if (dfs(ans, 0, i, n)) {
                cout << i << endl;
                break;
            }
        }
    }
}
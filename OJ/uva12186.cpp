#include <iostream>
#include <vector>
#include <algorithm>

using std::sort;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::begin;
using std::endl;

static const int maxn{static_cast<int>(1e5+1)};
int T, N;
vector<vector<int>> tree(maxn);

int 
dp(int p)
{
    if (tree[p].empty()) {
        return 1;
    }
    vector<int> subnodes;
    for (const auto& x: tree[p]) {
        subnodes.emplace_back(dp(x));
    }
    sort(begin(subnodes), end(subnodes));
    int x{(static_cast<int>(tree[p].size()*T)-1)/100 + 1};
    int ans{0};
    for (int i{0}; i < x; ++i) {
        ans += subnodes[i];
    }
    return ans;
}

int
main()
{
    while (cin >> N >> T && N && T) {
        int p;
        for (int i{1}; i <= N; ++i) {
            cin >> p;
            tree[p].push_back(i);
        }
        cout << dp(0) << endl;
        for (int i{0}; i <= N; ++i) {
            tree[i].clear();
        }
    }
}
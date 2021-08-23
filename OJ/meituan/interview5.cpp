#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::max;


void
dfs(int u, vector<vector<int>>& g, vector<int>& weights, vector<int>& colors)
{
    unordered_map<int, int> dp;
    for (auto &v: g[u]) {
        if (weights[v] < 0) {
            dfs(v, g, weights, colors);
        } 
        dp[colors[v]] += weights[v]+1;
    }
    int maxweight{0};
    for (auto &it: dp) {
        maxweight = max(it.second, maxweight);
    }
    weights[u] = maxweight;
}

int
main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n+1, vector<int>{});
    vector<int> colors(n+1, 0);
    vector<int> weights(n+1, 0);
    for (int i{1}; i <= n; ++i) {
        cin >> colors[i];
    }
    int m;
    for (int i{2}; i <= n;++i) {
        cin >> m;
        int p = i;
        if (p > m) std::swap(p, m);
        g[p].push_back(m);
    }
    for (int i{1}; i <= n; ++i) {
        cin >> weights[i];
    }
    dfs(1, g, weights, colors);
    for (int i{1}; i <= n; ++i) {
        if (i > 1) cout << ' ';
        cout << weights[i];
    }
    cout << endl;
}
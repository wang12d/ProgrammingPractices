#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

static const int maxn{100000 + 1};
static const int INF{maxn};
static vector<vector<int>> d(maxn, vector<int>(3, 0));
static vector<vector<int>> G(maxn, vector<int>{});
static vector<int> prev(maxn, -1);
static vector<int> nodes;

void
builTree(int u, int p)
{
    nodes.emplace_back(u);
    prev[u] = p;
    for (auto &v: G[u]) {
        if (p != v) {
            builTree(v, u);
        }
    }
}

int
main()
{
    int N, tmp;
    while (cin >> N && N > 0) {
        int a, b;
        nodes.clear();
        for (int i{0}; i < N; ++i) {
            G[i].clear();
            prev[i] = -1;
        }
        for (auto i{1}; i < N; ++i) {
            cin >> a >> b;
            --a; --b;
            G[a].emplace_back(b);
            G[b].emplace_back(a);
        }
        builTree(0, -2);
        // Start from leaf nodes
        for (auto it{nodes.rbegin()}; it != nodes.rend(); ++it) {
            int u{*it};
            d[u][0] = 1; d[u][1] = 0;
            for (auto &v: G[u]) {
                if (prev[u] != v) {
                    d[u][0] += std::min(d[v][1], d[v][0]);
                    d[u][1] += d[v][2];
                    if (d[u][0] > INF) {
                        d[u][0] = INF;
                    }
                    if (d[u][1] > INF) {
                        d[u][1] = INF;
                    }
                }
            }
            d[u][2] = INF;
            for (auto &v: G[u]) {
                if (prev[u] != v) {
                    d[u][2] = std::min(d[u][2], d[u][1]-d[v][2]+d[v][0]);
                }
            }
        }
        int v{nodes.front()};
        cout << std::min(d[v][0], d[v][2]) << std::endl;
        cin >> N;
    }
}
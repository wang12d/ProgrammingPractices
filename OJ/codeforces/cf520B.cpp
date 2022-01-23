#include <bits/stdc++.h>

using namespace std;

vector<bool> vis(static_cast<int>(1e6), false);

int
main()
{
    int n, m;
    cin >> n >> m;
    queue<pair<int,int>> q; q.push({n,0});

    int ans{static_cast<int>(1e9)};
    while (!q.empty()) {
        auto p{q.front()}; q.pop();
        if (p.first >= m) {
            ans = min(ans, p.second+p.first-m);
        } else {
            if (!vis.at(p.first*2)) {
                vis.at(p.first*2) = true;
                q.push({p.first*2, p.second+1});
            }
            if (p.first-1>=0 && !vis.at(p.first-1)) {
                vis.at(p.first-1) = true;
                q.push({p.first-1, p.second+1});
            }
        }
    }
    cout << ans << endl;
}
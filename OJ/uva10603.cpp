#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>

using std::priority_queue;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::generate;
using std::min;

class State {
public:
    int pouringWater;
    vector<int> glass;

    State():pouringWater{0}, glass{0, 0, 0} {}

    bool operator < (const State& oth) const {
        return this->pouringWater > oth.pouringWater;
    }
};

static const int MAXN{200+16};
static const int MAXC{3};
vector<vector<bool>> vis(MAXN, vector<bool>(MAXN, false));
vector<int> cap(MAXC, 0);
vector<int> ans(MAXN, -1);

int
main(int argc, char** argv)
{
    int T;
    int d;
    cin >> T;
    while (T--) {
        cin >> cap[0] >> cap[1] >> cap[2] >> d;
        generate(ans.begin(), ans.end(), [](){
            return -1;
        });
        for_each(vis.begin(), vis.end(), [](vector<bool>& a) {
            generate(a.begin(), a.end(), []() {
                return false;
            });
        });
        State s;
        s.glass[2] = cap[2];
        priority_queue<State> pq;
        pq.push(s);
        vis[s.glass[0]][s.glass[1]] = true;
        while (!pq.empty()) {
            auto t{pq.top()}; pq.pop();
            for (int i{0}; i < MAXC; ++i) {
                if (ans[t.glass[i]] < 0 || ans[t.glass[i]] > t.pouringWater) {
                    ans[t.glass[i]] = t.pouringWater;
                }
            }
            if (ans[d] >= 0) {
                break;
            }
            for (int i{0}; i < MAXC; ++i) {
                for (int j{0}; j < MAXC; ++j) {
                    if (i != j) {
                        // pouring water from i -> j
                        if (t.glass[i] == 0 || t.glass[j] == cap[j]) continue;
                        int minimumWater = min(cap[j], t.glass[i]+t.glass[j]) - t.glass[j];
                        State u{t};
                        u.glass[i] -= minimumWater;
                        u.glass[j] += minimumWater;
                        u.pouringWater += minimumWater;
                        if (!vis[u.glass[0]][u.glass[1]]) {
                            vis[u.glass[0]][u.glass[1]] = true;
                            pq.push(u);
                        }
                    }
                }
            }
        }
        while (d >= 0) {
            if (ans[d] >= 0) {
                cout << ans[d] << ' ' << d << endl;
                break;
            } else {
                d--;
            }

        }
    }
}
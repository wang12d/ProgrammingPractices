#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using std::queue;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

static const int MAXH{16};
static const int MAXG{3};
static const int MAXM{5};

int w,h,n;

vector<vector<int>> graphMap(MAXH, vector<int>(MAXH, 0));

bool 
viableMove(const vector<int>& prevLoc, const vector<int>& newLoc)
{
    if (n == 3) {
        if (newLoc[0] == newLoc[1] || newLoc[0] == newLoc[2] || newLoc[1] == newLoc[2]) {
            return false;
        }
    } else if (n == 2) {
        if (newLoc[0] == newLoc[1]) {
            return false;
        }
    }
    for (auto i{0}; i < n; ++i) {
        for (auto j{0}; j < n; ++j) {
            if (i != j) {
                if (prevLoc[i] == newLoc[j] && prevLoc[j] == newLoc[i]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int
bfs(vector<vector<int>>& g, vector<int>& targetCH, vector<int>& initLoc, vector<int>& targetLoc, int viablePath)
{
    queue<std::pair<vector<int>,int>> q;
    vector<bool> vis(viablePath*viablePath*viablePath, false);
    if (n == 1) {
        vis[initLoc[0]] = true;
    } else if (n == 2) {
        vis[initLoc[0]*viablePath+initLoc[1]] = true;
    } else {
        vis[initLoc[0]*viablePath+initLoc[1]*viablePath*viablePath+initLoc[2]] = true;
    }
    q.push({initLoc, 0});
    while (!q.empty()) {
        auto v{q.front()}; q.pop();
        bool ans{true};
        for (int i{0}; i < n; ++i) {
            if (v.first[i] != targetLoc[targetCH[i]-'a']) {
                ans = false;
                break;
            }
        }
        if (ans) {
            return v.second;
        }
        if (n == 3) {
            for (auto &i: g[v.first[0]]) {
                for (auto &ii: g[v.first[1]]) {
                    for (auto &iii: g[v.first[2]]) {
                        vector<int> nLoc{i, ii, iii};
                        if (!vis[i*viablePath+ii*viablePath*viablePath+iii] && viableMove(v.first, nLoc)) {
                            vis[i*viablePath+ii*viablePath*viablePath+iii] = true;
                            q.push({nLoc, v.second+1});
                        }
                    }
                }
            }
        } else if (n == 2) {
            for (auto &i: g[v.first[0]]) {
                for (auto &ii: g[v.first[1]]) {
                    vector<int> nLoc{i, ii};
                    if (!vis[i*viablePath+ii] && viableMove(v.first, nLoc)) {
                        vis[i*viablePath+ii] = true;
                        q.push({nLoc, v.second+1});
                    }
                }
            }
        } else {
            for (auto &i: g[v.first[0]]) {
                vector<int> nLoc{i};
                if (!vis[i] && viableMove(v.first, nLoc)) {
                    vis[i] = true;
                    q.push({nLoc, v.second+1});
                }
            }
        }
    }
    return -1;
}

int
main(int argc, char** argv)
{
    while (true) {
        cin >> w >> h >> n;
        if (w == 0) {
            break;
        }
        std::for_each(graphMap.begin(), graphMap.end(), [](vector<int>& v){
            std::generate(v.begin(), v.end(), [](){
                return -1;
            });
        });
        vector<std::string> maze(h);
        vector<int> targetLoc(26, 0);
        vector<int> initLoc(MAXG, 0);
        vector<int> targetCH(MAXG, 0);
        std::getline(cin, maze.front());
        for (int i{0}; i < h; ++i) {
            std::getline(cin, maze[i]);
        }
        int viablePath{0}; int chCnt{0};
        for (auto i{0}; i < h; ++i) {
            for (auto j{0}; j < w; ++j) {
                auto ch{maze[i][j]};
                if (ch == '#') continue;
                graphMap[i][j] = viablePath;
                if (isalpha(ch)) {
                    if (isupper(ch)) {
                        targetLoc[tolower(ch)-'a'] = viablePath;
                    } else {
                        initLoc[chCnt] = viablePath;
                        targetCH[chCnt++] = ch;
                    }
                }
                viablePath++;
            }
        }

        // Build new graph
        vector<vector<int>> g(viablePath, vector<int>{});
        for (auto i{0}; i < h; ++i) {
            for (auto j{0}; j < w; ++j) {
                auto current{graphMap[i][j]};
                if (current >= 0) {
                    int down, right;
                    g[current].push_back(current);
                    if (i + 1 < h && (down=graphMap[i+1][j]) >= 0) {
                        g[current].push_back(down);
                        g[down].push_back(current);
                    }
                    if (j + 1 < w && (right=graphMap[i][j+1]) >= 0) {
                        g[current].push_back(right);
                        g[right].push_back(current);
                    }
                }
            }
        }
        cout << bfs(g, targetCH, initLoc, targetLoc, viablePath) << endl;
    }
}
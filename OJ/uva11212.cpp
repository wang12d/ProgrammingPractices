#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

static const int MAXD{9};

int
wrongSuccessor(const vector<int>& vec, int n)
{
    int cnt{0};
    for (auto i{1}; i < n; ++i) {
        if (vec[i] != vec[i-1]+1) {
            cnt++;
        }
    }
    if (vec[n-1] != n) cnt++;
    return cnt;
}

bool
dfs(int depth, vector<int>& items, int n, int maxd, int& ans) 
{
    if (3*depth+wrongSuccessor(items, n) > 3*maxd) {
        return false;
    }
    if (std::is_sorted(items.begin(), items.begin()+n)) {
        return true;
    }
    if (depth < maxd) {
        vector<int> tmp(MAXD, 0);
        vector<int> old{items.begin(), items.end()};
        for (int i{0}; i < n; ++i) {
            for (int j{i}; j < n; ++j) {
                int cnt{0};
                for (int k{0}; k < n; ++k) {
                    if (k < i || k > j) {
                        tmp[cnt++] = items[k];
                    }
                }
                for (int k{0}; k <= cnt; ++k) {
                    int c{0};
                    for (int p{0}; p < k; ++p) items[c++] = tmp[p];
                    for (int p{i}; p <= j; ++p) items[c++] = old[p];
                    for (int p{k}; p < cnt; ++p) items[c++] = tmp[p];
                    if (dfs(depth+1, items, n, maxd,  ans)) {
                        return true;
                    } 
                    for (int p{0}; p < n; ++p) items[p] = old[p];
                }
            }
        }
    }
    return false;
}

int
main(int argc, char** argv)
{
    vector<int> items(MAXD, 0);
    int n; int c{0};
    while (true) {
        cin >> n;
        if (!n) break;
        for (int i{0}; i < n; ++i) {
            cin >> items[i];
        }
        int ans{MAXD};
        for (int i{0}; i <= MAXD; ++i) {
            if (dfs(0, items, n, i, ans)) {
                cout << "Case " << ++c << ": " << i << endl;
                break;
            }
        }
    }
}
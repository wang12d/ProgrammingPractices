#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <deque>

using std::cin;
using std::cout;
using std::endl;
using std::function;
using std::vector;
using std::for_each;
using std::deque;
using combs = vector<vector<int>>;

static const int maxn{20};

vector<vector<combs>>
findAllCombs()
{
    vector<vector<combs>> ans(maxn+1, vector<combs>(maxn+2));
    function<void(int, int, int, vector<int>&, combs&)> dfs = [&dfs](int i, int n, int k, vector<int>& c, combs& all) {
        if (k == 0) {
            all.emplace_back(c);
            return;
        }
        for (int j{i}; j < n; ++j) {
            c.emplace_back(j);
            dfs(j+1, n, k-1, c, all);
            c.pop_back();
        }
    };
    combs all;
    vector<int> c;
    for (int n{1}; n <= maxn; ++n) {
        for (int k{0}; k <= n; ++k) {
            c.clear();
            all.clear();
            dfs(0, n, k, c, all);
            ans[n][k] = all;
        }
    }
    return ans;
}

int
main()
{
    auto allcombs{findAllCombs()};
    int n, r;
    vector<double> probs(maxn, 0);
    int k{0};
    while (cin >> n >> r && n) {
        for (int i{0}; i < n; ++i) {
            cin >> probs[i];
        }
        double demo{0.0};
        for (auto &combs: allcombs[n][r]) {
            double p{1.0}; vector<bool> buy(n, false);
            for (auto &x: combs) {
                buy[x] = true;
            }
            for (int i{0}; i < n; ++i) {
                if (buy[i]) {
                    p *= probs[i];
                } else {
                    p *= (1-probs[i]);
                }
            }
            demo += p;
        }
        printf("Case %d:\n", ++k);
        deque<double> aa(probs.begin(), probs.begin()+n);
        int m{n-1};
        for (int i{0}; i < n; ++i) {
            double mul{aa.front()}; aa.pop_front();
            double ans{0.0};
            for (auto& combs: allcombs[n-1][r-1]) {
                double p{1.0}; vector<bool> buy(n-1, false);
                for (auto &x: combs) {
                    buy[x] = true;
                }
                for (int i{0}; i < m; ++i) {
                    if (buy[i]) {
                        p *= aa[i];
                    } else {
                        p *= (1-aa[i]);
                    }
                }
                ans += p;
            }
            aa.push_back(mul);
            printf("%.6lf\n", mul*ans/demo);
        }
    }
}
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::fill;
using std::vector;
using std::pair;

int
main(int argc, char** argv)
{
    int T;
    std::string a, b;
    size_t n, m; static const int maxc{26};
    cin >> T;
    vector<vector<int>> dp(2, vector<int>(5000+1, 0));
    vector<vector<int>> cost(2, vector<int>(5000+1, 0));
    vector<pair<int,int>> loca(maxc, {INT32_MAX, -1});
    vector<pair<int,int>> locb(maxc, {INT32_MAX, -1});
    while (T--) {
        cin >> a >> b;
        n = a.size(); m = b.size();
        std::for_each(loca.begin(), loca.end(), [](pair<int, int>& p) {
            p.first = INT32_MAX;
            p.second = 0;
        });
        std::for_each(locb.begin(), locb.end(), [](pair<int, int>& p) {
            p.first = INT32_MAX;
            p.second = 0;
        });
        for (int i{0}; i < n; ++i) {
            int ind{a[i]-'A'};
            loca[ind].first = std::min(loca[ind].first, i+1);
            loca[ind].second = i+1;
        }
        for (int j{0}; j < m; ++j) {
            int ind{b[j]-'A'};
            locb[ind].first = std::min(locb[ind].first, j+1);
            locb[ind].second = j+1;
        }
        std::for_each(dp.begin(), dp.end(), [](vector<int>& vec) {
            fill(vec.begin(), vec.end(), 0);
        });
        std::for_each(cost.begin(), cost.end(), [](vector<int>& vec) {
            fill(vec.begin(), vec.end(), 0);
        });
        int t{1};
        for (int i{0}; i <= n; ++i) {
            for (int j{0}; j <= m; ++j) {
                if (!i && !j) continue;
                int v1{INT32_MAX}; int v2{INT32_MAX};
                if (i) {
                    v1 = dp[t^1][j] + cost[t^1][j];
                }
                if (j) {
                    v2 = dp[t][j-1] + cost[t][j-1];
                }
                dp[t][j] = std::min(v1, v2);
                if (i) {
                    cost[t][j] = cost[t^1][j];
                    if (loca[a[i-1]-'A'].first == i &&  locb[a[i-1]-'A'].first > j) cost[t][j]++; 
                    if (loca[a[i-1]-'A'].second == i && locb[a[i-1]-'A'].second <= j) cost[t][j]--;
                } else if (j) {
                    cost[t][j] = cost[t][j-1];
                    if (locb[b[j-1]-'A'].first == j &&  loca[b[j-1]-'A'].first > i) cost[t][j]++;
                    if (locb[b[j-1]-'A'].second == j && loca[b[j-1]-'A'].second <= i) cost[t][j]--;
                }
            }
            t ^= 1;
        }
        cout << dp[t^1][m] << endl;
    }
}
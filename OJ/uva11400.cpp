#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::fill;

struct Lamp
{
    int V, K, C, L;

    bool operator<(const Lamp& rhs) {
        return V < rhs.V;
    }
};

int
main(int argc, char** argv)
{
    static const int n{1000+1};

    vector<Lamp> lamps(n+23);
    vector<int> curr(n+23, 0);
    vector<int> dp(n+23, 0);
    int t;
    while (cin >> t && t) {
        for (int i{0}; i < t; ++i) {
            cin >> lamps[i].V >> lamps[i].K >> lamps[i].C >> lamps[i].L;
        }
        std::fill(dp.begin(), dp.end(), INT32_MAX);
        dp[0] = 0;
        sort(lamps.begin(), lamps.begin()+t);
        for (int i{0}; i < t; ++i) {
            curr[i+1] = curr[i] + lamps[i].L;
        }
        for (int i{1}; i <= t; ++i) {
            for (int j{0}; j < i; ++j) {
                dp[i] = std::min(dp[j]+(curr[i]-curr[j])*lamps[i-1].C+lamps[i-1].K, dp[i]);
            }
        }
        cout << dp[t] << endl;
    }
}
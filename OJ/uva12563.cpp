#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::max;

static const int maxn{50};
vector<int> dp(maxn*180+678);
vector<int> totalLength(maxn*180+678);

int
main(int argc, char** argv)
{
    int T;
    cin >> T;
    int n, t;
    int c{0};
    while (T--) {
        cin >> n >> t; int len;
        std::fill(dp.begin(), dp.end(), 0);
        std::fill(totalLength.begin(), totalLength.end(), 0);
        for (int i{0}; i < n; ++i) {
            cin >> len;
            for (int j{t-1}; j >= len; --j) {
                int v{dp[j-len]+1};
                if (dp[j] <= v) {
                    if (dp[j] == v) {
                        totalLength[j] = std::max(totalLength[j], totalLength[j-len] + len);
                    } else {
                        totalLength[j] = totalLength[j-len] + len;
                    }
                    dp[j] = v;
                }
            }
        }
        int maxsong{-1}; int maxlen{-1};
        for (int i{0}; i < t; ++i) {
            if (dp[i]+1 >= maxsong) {
                maxsong = dp[i]+1;
                if (dp[i]+1 == maxsong) {
                    maxlen = std::max(totalLength[i]+678, maxlen);
                } else {
                    maxlen = totalLength[i]+678;
                }
            }
        }
        cout <<"Case " << ++c << ": " << maxsong << ' ' << maxlen << endl;
    }
}
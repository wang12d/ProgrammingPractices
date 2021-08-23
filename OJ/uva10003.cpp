#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::vector;

static const int maxn{1024};

vector<vector<int>> dp(maxn, vector<int>(maxn, 0));

int
findCost(int l, int offset, int i, int j, vector<int>& length)
{
    if (dp[i][j] != INT32_MAX) {
        return dp[i][j];
    }
    if (j < i) {
        return 0;
    }
    for (int k{i}; k <= j; ++k) {
        dp[i][j] = std::min(findCost(length[k]-offset, offset, i, k-1, length)+l+findCost(l-length[k]+offset, length[k], k+1, j, length), dp[i][j]);
    }
    return dp[i][j];
}

int
main(int argc, char** argv)
{
    int l, n;
    vector<int> length(maxn, 0);
    while (true) {
        cin >> l;
        if (!l) break;
        cin >> n;
        for (int i{0}; i < n; ++i) {
            cin >> length[i];
        }
        std::for_each(dp.begin(), dp.end(), [](vector<int>& v) {
            std::fill(v.begin(), v.end(), INT32_MAX);
        });
        printf("The minimum cutting is %d.\n", findCost(l, 0, 0, n-1, length));
    }
}
#include <iostream>
#include <vector>

int
main(int argc, char** argv)
{
    const static int maxm{3};
    const static int maxn{4000};
    const static int init{-1};
    std::vector<int> pieces;
    std::vector<int> dp(maxn+1, init);
    int n; int m;
    std::cin >> n;
    for (int i{0}; i < maxm; ++i) {
        std::cin >> m;
        for (auto &x: pieces) {
            if (x == m) {
                m = -1;
            }
        }
        if (m > 0) {
            pieces.emplace_back(m);
        }
    }
    dp.front() = 0;
    for (int i{1}; i <= n; ++i) {
        for (auto& p: pieces) {
            if (i >= p && dp.at(i-p) >= 0) {
                dp[i] = std::max(dp.at(i-p)+1, dp.at(i));
            }
        }
    }
    std::cout << dp.at(n) << std::endl;
}
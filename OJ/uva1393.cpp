#include <iostream>
#include <vector>


using ull = unsigned long long;
static const int maxn{300+1};

std::vector<std::vector<ull>> dp(maxn, std::vector<ull>(maxn, 0));
std::vector<std::vector<ull>> ans(maxn, std::vector<ull>(maxn, 0));

ull
gcd(ull a, ull b)
{
    if (a == 0) {
        return b;
    }
    return gcd(b%a, a);
}

int
main()
{
    for (int i{1}; i < maxn; ++i) {
        for (int j{1}; j < maxn; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (gcd(i, j) == 1);
        }
    }
    for (int i{1}; i < maxn; ++i) {
        for (int j{1}; j < maxn; ++j) {
            ans[i][j] = ans[i-1][j] + ans[i][j-1] + dp[i][j] - dp[i>>1][j>>1] - ans[i-1][j-1];
        }
    }
    int n, m;
    while (std::cin >> n >> m && n) {
        std::cout << (ans[n-1][m-1] << 1) << std::endl;
    }
}

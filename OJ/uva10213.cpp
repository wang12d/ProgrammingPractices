#include <iostream>
#include <algorithm>

using ull = __uint128_t;

static inline ull
calculatePlanarGraph(ull n)
{
    switch (n)
    {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 4;
    default:
        return n + (n-3)*(n-2)*(n*n+5*n) / 24 + ((n*(n-3))>>1) + 1 - ((n*(n-3)*(n-2)) / 4);
    }
}

std::string
convertString(ull x)
{
    std::string ans;
    while (x) {
        ans.push_back('0'+x%10);
        x /= 10;
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int
main()
{
    int T, n;
    std::cin >> T;
    while (T--) {
        std::cin >> n;

        std::cout << convertString(calculatePlanarGraph(n)) << std::endl;
    }
}
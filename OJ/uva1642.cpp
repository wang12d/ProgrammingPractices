#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::pair;

using ull = unsigned long long;
using pll = pair<ull, ull>;

static const int maxn{100000};
vector<ull> A(maxn, 0);
vector<vector<pll>> subgcd;

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
    int T, n;
    cin >> T;
    while (T--) {
        subgcd.clear();
        cin >> n;
        ull ans{0};
        for (int i{0}; i < n; ++i) {
            cin >> A[i];
            subgcd.emplace_back();
            ans = max(ans, A[i]);
            if (i) {
                auto subsequnce{subgcd[i-1].size()};
                for (int j{0}; j < subsequnce; ++j) {
                    ull g{gcd(subgcd[i-1][j].first, A[i])};
                    ans = max(ans, g*(subgcd[i-1][j].second+1));
                    if (subgcd[i].empty() || subgcd[i].back().first != g) {
                        subgcd[i].push_back({g, subgcd[i-1][j].second+1});
                    } else {
                        subgcd[i].back().second = max(subgcd[i].back().second, subgcd[i-1].back().second+1);
                    }
                }
            }
            subgcd[i].push_back({A[i], 1});
        }
        cout << ans << endl;
    }
}
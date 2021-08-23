#include <vector>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::fill;

static const int maxn{1000};

int
main(int argc, char** argv)
{
    int T;
    cin >> T;
    std::string s;
    vector<vector<bool>> isPalindromes(maxn+1, vector<bool>(maxn+1, false));
    vector<int> dp(maxn+1, INT32_MAX);
    while (T--) {
        cin >> s;
        auto sz{s.size()};
        fill(dp.begin(), dp.end(), INT32_MAX);
        dp[0] = 0;
        std::for_each(isPalindromes.begin(), isPalindromes.end(), [](vector<bool>& vec) {
            fill(vec.begin(), vec.end(), false);
        });
        for (size_t length{1}; length <= sz; ++length) {
            for (size_t i{0}; i+length <= sz; ++i) {
                size_t tail{i+length-1};
                if (s[tail] == s[i]) {
                    if (tail == i || tail-1 < i+1 || isPalindromes[i+2][tail]) {
                        isPalindromes[i+1][tail+1] = true;
                    }
                }
            }
        }
        for (size_t i{1}; i <= sz; ++i) {
            for (size_t j{0}; j < i; ++j) {
                if (isPalindromes[j+1][i]) {
                    dp[i] = std::min(dp[j]+1, dp[i]);
                }
            }
        }
        cout << dp[sz] << endl;
    }
}
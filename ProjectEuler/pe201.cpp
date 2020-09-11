#include "Toolbox.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int max_size(int, int);

int
main(int argc, char** argv)
{
    Toolbox<int>::timer();
    static unsigned long maxn = 100;
    static unsigned long choose = 50;
    if (argc > 1) {
        sscanf(argv[1], "%ld", &maxn);
        if (argc > 2) {
            sscanf(argv[2], "%ld", &choose);
        }
    }
    unsigned long max_val = max_size(maxn, choose);
    vector<vector<bool>> dp(choose+1);
    vector<vector<bool>> dup(choose+1);
    vector<int> squares{};
    for (int i = 1; i <= maxn; ++i) squares.push_back(i*i);
    dp[0].resize(1, true);
    dup[0].resize(1, false);
    for (int i = 1; i <= choose; ++i) {
        dp[i].resize(max_size(maxn, i), false);
        dup[i].resize(max_size(maxn, i), false);
    }
    for (auto &q: squares) {
        for (int i = choose; i >= 1; --i) {
            for (auto sum = 0; sum < dp[i-1].size(); ++sum) {
                if (dp[i-1][sum]) {
                    int current_sum = sum + q;
                    if (dp[i][current_sum] || dup[i-1][sum]) {
                        dp[i][current_sum] = true;
                        dup[i][current_sum] = true;
                    }
                    else {
                        dp[i][current_sum] = true;
                    }
                }
            }
        }
    }
    long res = 0;
    for (int i = 1; i <= max_val; ++i) {
        if (dp[choose][i] && !dup[choose][i]) {
            res += i;
        }
    }
    cout << res << endl;
    Toolbox<int>::timeCost();
}

int
max_size(int n, int k)
{
    int max_val = 0;
    for (int i = 0; i < k; ++i) {
        max_val += (n-i)*(n-i);
    }
    return max_val;
}
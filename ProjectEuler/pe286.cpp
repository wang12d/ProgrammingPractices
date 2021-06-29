#include <bits/stdc++.h>
#include "Toolbox.h"

using std::vector;
using std::cout;
using std::endl;

double prob(int, int, double);

int
main(int argc, char** argv)
{
    const double eplison{1e-11};
    const int p{50}; const int s{20};
    const double finP{0.02};
    vector<vector<double>> dp(p+1, vector<double>(s+1, 0.0));
    double maxp{static_cast<double>(INT_MAX)};
    double minp{static_cast<double>(50+eplison)};
    int round{1000};
    double guess;
    while (round--) {
        guess = (maxp+minp)/2;
        if (prob(p, s, guess)>finP) {
            minp = guess;
        } else {
            maxp = guess;
        }
    }
    printf("%.10f\n", guess);
}

double
prob(int p, int s, double guess)
{
    vector<vector<double>> dp(p+1, vector<double>(s+1, 0.0));
    dp[0][0] = 1.0;
    for (int i = 1; i <= p; ++i) {
        dp[i][0] = dp[i-1][0]*(i/guess);
        for (int j = 1; j <= std::min(i, s); ++j) {
            dp[i][j] = dp[i-1][j-1] * (1-i/guess) + dp[i-1][j]*(i/guess);
        }
    }
    return dp[p][s];
}
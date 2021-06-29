#include <bits/stdc++.h>

using std::vector;
using std::cout;
using std::endl;

int
main(int argc, char** argv)
{
    const auto maxn{500};
    vector<vector<double>> expectation(maxn+1, vector<double>(2, 0.0));
    for (int i{maxn-1}; i >= 0; --i) {
        double prob{static_cast<double>(1000-2*i-2)/1000};
        double dup{static_cast<double>(i+1)/1000};
        expectation[i][1] = (1+expectation[i+1][1]*prob) / (1-dup);
        expectation[i][0] = (1+expectation[i][1]/1000+expectation[i+1][0]*prob) / (1-dup);
    }
    cout << std::fixed << std::setprecision(8) <<  expectation[0][0] << endl;
}
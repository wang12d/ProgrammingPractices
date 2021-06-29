#include <bits/stdc++.h>

using std::cout;
using std::endl;
using std::vector;

int
main(int argc, char** argv)
{
    const int grid{30};
    const int bells{50};
    vector<vector<double>> emptyGrid(grid, vector<double>(grid, 1.0));
    for (int i = 0; i < grid; ++i) {
        for (int j = 0; j < grid; ++j) {
            vector<vector<double>> flea(grid, vector<double>(grid, 0.0));
            flea[i][j] = 1;
            for (int b = 0; b < bells; ++b) {
                vector<vector<double>> nextPos(grid, vector<double>(grid, 0.0));
                for (int i = 0; i < grid; ++i) { 
                    for (int j = 0; j < grid; ++j) {
                        if (flea[i][j] == 0) continue;
                        int dire{4};
                        if (i == 0 || i == grid-1) dire--;
                        if (j == 0 || j == grid-1) dire--;
                        double prob{1.0/dire}; double nextProb{flea[i][j]*prob};
                        if (j != grid-1) nextPos[i][j+1] += nextProb;
                        if (j != 0) nextPos[i][j-1] += nextProb;
                        if (i != 0) nextPos[i-1][j] += nextProb;
                        if (i != grid-1) nextPos[i+1][j] += nextProb;
                    }
                }
                flea = std::move(nextPos);
            }
            for (int i = 0; i < grid; ++i) {
                for (int j = 0; j < grid; ++j) {
                    emptyGrid[i][j] *= (1-flea[i][j]);
                }
            }
        }
    }
    double res{.0};
    for (auto &v: emptyGrid) {
        for (auto &u: v) {
            res += u;
        }
    }
    cout << std::fixed << std::setprecision(6) << res << endl;
}
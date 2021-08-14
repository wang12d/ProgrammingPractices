#include <iostream>
#include <vector>
#include <algorithm>


using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int
main(int argc, char** argv)
{
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        vector<vector<int>> indices(n, vector<int>(m, 0));
        vector<vector<int>> acc(n, vector<int>(m, 0));
        for (int i{0}; i < n; ++i) {
            for (int j{0}; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }
        int ans{INT32_MAX}; int first{-1};
        for (int i{m-1}; i >= 0; --i) {
            for (int j{0}; j < n; ++j) {
                if (i == m-1) {
                    acc[j][i] = matrix[j][i];
                } else {
                    vector<int> nextRow{j-1, j+1, j};
                    if (!j) nextRow[0] = n-1;
                    if (j == n-1) nextRow[1] = 0;
                    sort(nextRow.begin(), nextRow.end());
                    acc[j][i] = INT32_MAX;
                    for (const auto& r: nextRow) {
                        int v{acc[r][i+1]+matrix[j][i]};
                        if (v < acc[j][i]) {
                            acc[j][i] = v;
                            indices[j][i] = r;
                        }
                    }
                }
                if (i == 0 && acc[j][i] < ans) {
                    ans = acc[j][i]; first = j;
                }
            }
        }
        cout << first+1;
        for (int i{indices[first][0]}, j{1}; j < m; i = indices[i][j], j++) {
            cout << ' ' << i+1;
        }
        cout << endl << ans << endl;
    }
}
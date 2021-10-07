#include <iostream>
#include <vector>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

static const int nwheels{2};
static const int ncols{5};
static const int nrows{6};
static const int nchs{26};

vector<vector<string>> wheels(nwheels, vector<string>(nrows, ""));
bool contain[nwheels][nrows][nchs];

int
main()
{
    int T, k;
    cin >> T;
    vector<vector<char>> rowChars(nrows, vector<char>{});
    vector<int> cnt(ncols+1, 1);
    while (T--) {
        cin >> k;
        memset(contain, 0, sizeof(contain));
        for (int i{0}; i < nrows; ++i) {
            rowChars[i].clear();
        }
        for (int x{0}; x < nwheels; ++x) {
            for (int i{0}; i < nrows; ++i) {
                cin >> wheels[x][i];
                for (int j{0}; j < ncols; ++j) {
                    contain[x][j][wheels[x][i][j]-'A'] = true;
                }
            }
        }
        for (int i{0}; i < ncols; ++i) {
            for (int j{0}; j < nchs; ++j) {
                if (contain[0][i][j] && contain[1][i][j]) {
                    rowChars[i].emplace_back(j+'A');
                }
            }
        }
        cnt.back() = 1;
        for (int i{ncols-1}; i >= 0; --i) {
            cnt[i] = cnt[i+1] * rowChars[i].size();
        }
        if (cnt.front() < k) {
            puts("NO");
        } else {
            --k;
            for (int i{0}; i < ncols; ++i) {
                putchar(rowChars[i][k/cnt[i+1]]);
                k %= cnt[i+1];
            }
            putchar('\n');
        }
    }
}
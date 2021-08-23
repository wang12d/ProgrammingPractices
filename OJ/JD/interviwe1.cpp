#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::pair;

const int maxn = 1000+1;
const int L = 2;
vector<int> dx{1, 1};
vector<int> dy{-1, 1};

int
main()
{
    vector<vector<int>> hasPeople(2, vector<int>(2*maxn+23, 0));
    int n, x, y;
    cin >> n;
    int ptr = 0;
    vector<pair<int,int>> neg(n);
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        hasPeople[0][x+y]++;
        hasPeople[1][(x-y+maxn)]++;
    }
    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2*maxn+23; ++j) {
            int m;
            if ((m = hasPeople[i][j]) > 0) {
                ans += ((m*(m-1)) >> 1);
            }
        }
    }
    cout << ans << endl;
}
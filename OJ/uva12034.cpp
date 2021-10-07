#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

static const int maxn{1000+1};
static const int mod{10056};

vector<vector<int>> combination(maxn, vector<int>(maxn, 0));
vector<vector<int>> f(maxn, vector<int>(maxn, 0));
vector<int> ans(maxn, 0);

int
main()
{
    combination[0][0] = 1;
    for (int i{1}; i < maxn; ++i) {
        f[i][1] = 1;
        combination[i][0] = 1;
        for (int k{1}; k <= i; ++k) {
            combination[i][k] = (combination[i-1][k] + combination[i-1][k-1]) % mod;
        }
    }
    ans[1] = 1;
    for (int n{2}; n < maxn; ++n) {
        for (int k{1}; k <= n; ++k) {
            for (int i{1}; i <= n; ++i) {
                if (k-1 > n-i) {
                    break;
                }
                f[n][k] += ((combination[n][i]%mod) * (f[n-i][k-1]%mod)) % mod;
            }
            ans[n] = (ans[n] + f[n][k]) % mod;
        }
    }
    int T, n;
    cin >> T;
    for (int i{1}; i <= T; ++i) {
        cout << "Case " << i << ": ";
        cin >> n;
        cout << ans[n] << endl;
    }
}
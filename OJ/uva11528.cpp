#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

static const int maxn{1000};
vector<vector<bool>> mod(maxn, vector<bool>(maxn, false));

uint64_t
fastMod(uint64_t base, uint64_t expt, uint64_t M)
{
    uint64_t res{1};
    while (expt) {
        if (expt & 1) {
            res = ((base%M) * (res%M)) % M;
        }
        base = ((base%M) * (base%M)) % M;
        expt >>= 1;
    }
    return res;
}

int
main()
{
    int t;
    cin >> t;
    uint64_t a, b;
    int n; vector<int> m(maxn*maxn+3, 0);
    for (int i{0}; i < t; ++i) {
        cin >> a >> b >> n;
        std::for_each(mod.begin(), mod.end(), [](vector<bool>& a) {
            std::fill(a.begin(), a.end(), false);
        });
        int upper{n*n}; int prev{0}; int cur{1};
        int cnt{2}; int j{2}; m[0] = 0; m[1] = 1%n;
        for (; ; ++j) {
            if (mod[prev][cur]) {
                j -= 2; break;
            }
            mod[prev][cur] = true;
            int tmp{cur};
            cur = (prev + cur)%n;
            prev = tmp%n;
            m[j] = cur;
        }
        cout << m[fastMod(a, b, j)] << endl;
    }
}
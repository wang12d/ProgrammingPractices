#include <iostream>
#include <vector>
#include <algorithm>

using std::lower_bound;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

static const int maxn{4000};

int
main()
{
    int T; int n;
    cin >> T; vector<int64_t> A(maxn, 0), B(maxn, 0), C(maxn, 0), D(maxn, 0);
    vector<int64_t> sv(maxn*maxn, 0);
    while (T--) {
        cin >> n;
        for (int i{0}; i < n; ++i) {
            cin >> A[i] >> B[i] >> C[i] >> D[i];
        }
        for (int i{0}; i < n; ++i) {
            int64_t a{A[i]};
            for (int j{0}; j < n; ++j) {
                sv[i*n+j] = a+B[j];
            }
        }
        int cnt{0}; int64_t up{n*n};
        std::sort(sv.begin(), sv.begin()+up);
        auto begin{sv.begin()}; auto end{sv.begin()+up};
        for (int i{0}; i < n; ++i) {
            int64_t c{C[i]};
            for (int j{0}; j < n; ++j) {
                int64_t val{-c-D[j]};
                auto it{lower_bound(begin, end, val)};
                auto upit{std::upper_bound(begin, end, val)};
                if (it != sv.end() && *it == val) {
                    cnt += upit-it;
                }
            }
        }
        cout << cnt << endl;
        if (T) cout << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

int
main(int argc, char** argv)
{
    using ull = unsigned long long;

    static const ull maxk{static_cast<ull>(1e8)};
    ull v_upper_bound{static_cast<ull>(1e4/sqrt(2))};

    ull ans{0};
    for (ull v{1}; v <= v_upper_bound; ++v) {
        ull t_upper_bound{static_cast<ull>(sqrt(maxk-v*v))};
        for (ull t{v+1}; t <= t_upper_bound; ++t) {
            if (__gcd(t, v) == 1 && (!((t & 1) && (v & 1)))) {
                ull m{2*t*v}, n{t*t-v*v};
                if (m < n) {
                    swap(m, n);
                }
                if (!((m & 1) && (n & 1))) {
                    ull x{m-n}, y{m+n}, z{m*n};
                    if ((((x%6)*(y%6)*(z%6))%6) != 0 || (((x%28)*(y%28)*(z%28))%28) != 0) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << "perfect triangle: " << ans << endl;
}
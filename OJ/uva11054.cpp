#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::endl;


int
main()
{
    int n;
    using ll = long long;
    while (cin >> n && n) {
        ll ans{0}; int v;
        ll curr{0};
        for (int i{0}; i < n; ++i) {
            cin >> v;
            ans += std::abs(curr);
            curr += v;
        }
        cout << ans << endl;
    }
}
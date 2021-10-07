#include <iostream>

using std::cin;
using std::cout;
using std::endl;


using ll = long long;

ll
findNumberOfDigits(ll n, ll t)
{
    ll magnitude{1};
    ll right{0}, left{0};
    ll ans{t == 0};
    while (n >= magnitude) {
        auto d{(n / magnitude) % 10};
        left = n % magnitude;
        right = n / magnitude / 10;
        if (d > t) {
            if (t == 0) {
                ans += right * magnitude;
            } else {
                ans += (right + 1) * magnitude;
            }
        } else if (d == t) {
            if (t == 0 && right) {
                ans += (right-1)*magnitude + left + 1;
            } else {
                ans += right * magnitude + left + 1;
            }
        } else {
            if (t == 0 && right) {
                ans += (right-1) * magnitude;
            } else {
                ans += right * magnitude;
            }
        }
        magnitude *= 10;
    }
    return ans;
}

int
main()
{
    int a, b;
    while (cin >> a >> b && a && b) {
        int n{std::max(a, b)}; int m{std::min(a, b)};
        for (int i{0}; i < 10; ++i) {
            if (i) cout << ' ';
            cout << findNumberOfDigits(n, i) - findNumberOfDigits(m-1, i);
        }
        cout << endl;
    }
}
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

using ull = unsigned long long;

int
main()
{
    ull n, k;
    while (cin >> n >> k) {
        ull ans{0}; 
        for (ull i{1}; i <= n;) {
            ull rem{k % i};
            ull div{k / i};
            ull last;
            if (!div) {
                last = n;
            } else {
                last = k / div;
                if (last > n) {
                    last = n;
                }
            }
            ull number{last-i+1};
            ans += rem * number - div * (number * (number-1) >>1);
            i = last+1;
        }
        cout << ans << endl;
    }
}
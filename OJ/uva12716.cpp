#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

static const int maxn{30000000};
vector<int> factors(maxn+1, 0);
vector<int> cnt(maxn+1, 0);

int
gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a%b);
}

int
main()
{
    int T; cin >> T;
    int N;
    for (auto i{1}; i <= maxn; ++i) {
        for (int j{2*i}; j <= maxn; j += i) {
            int b{j-i};
            if (i == (j^b)) {
                factors[j]++;
            }
        }
    }
    for (auto i{1}; i <= maxn; ++i) {
        cnt[i] = cnt[i-1] + factors[i];
    }
    int c{1};
    while (T--) {
        cin >> N;
        cout << "Case " << c++ << ": " << cnt[N] << endl;
    }
}
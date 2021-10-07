#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

static const int maxn{30+1};
static vector<int> f(maxn, 0);

int
main()
{
    int n;
    f[3] = 1;
    for (int i{4}; i < maxn; ++i) {
        f[i] = f[i-1]*2 + (1 << (i - 4 )) - f[i-4];
    }
    while (cin >> n && n) {
        cout << f[n] << endl;
    }
}
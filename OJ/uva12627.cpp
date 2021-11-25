#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::endl;
using std::cout;

using ll = long long;

ll
f(int k, int i)
{
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1 << k;
    }
    if (k == 0) {
        return 1;
    }
    if (i & 1) {
        return f(k-1, (i >> 1)+1) << 1;
    }
    return f(k, i-1) >> 1;
}

ll
S(int k, int i)
{
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1 << k;
    }
    if (k == 0) {
        return 1;
    }
    if (i & 1) {
        return S(k, i-1) + f(k, i);
    }
    return 3*S(k-1, i >> 1);
}

int
main(int argc, char** argv)
{
    int T;
    int k, a, b;
    cin >> T;
    for (int i{1}; i <= T; ++i) {
        cin >> k >> a >> b;
        cout << "Case " << i << ": " << S(k, b) - S(k, a-1) << endl;
    }
}
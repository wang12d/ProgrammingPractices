#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

static const int maxn{10001};

bool
verifyResult(vector<int>& input, int a, int b)
{
    int up{2*static_cast<int>(input.size())};
    vector<int> ans(up/2, (input.front()*a+b)%maxn);
    for (int i{3}; i <= up; i++) {
        if (i%2) {
            if (input[i/2] != (ans[i/2-1]*a+b)%maxn) {
                return false;
            }
        } else {
            ans[i/2-1] = (input[i/2-1] * a + b)%maxn;
        }
    }
    for (auto &x: ans) {
        cout << x << endl;
    }
    return true;
}

void
extend_gcd(int a, int b, int& d, int& x, int& y)
{
    if (!b) {
        d = a; x = 1; y = 0;
    } else {
        extend_gcd(b, a%b, d, y, x); y -= x*(a/b);
    }
}

int
main()
{
    int T;
    cin >> T;
    vector<int> input(T, 0);
    for (int i{0}; i < T; ++i) {
        cin >> input[i];
    }
    if (T == 1) {
        cout << input[0] << endl;
    } else {
        for (int a{0}; a < maxn; ++a) {
            int d, x, y;
            extend_gcd(a+1, maxn, d, x, y);
            int x2 = ((a*input[0]+input[1])%maxn)*((x+maxn)%maxn)%maxn;
            int b = (((x2-a*input[0])%maxn)+maxn)%maxn;
            if (verifyResult(input, a, b)) break;
        }
    }
}
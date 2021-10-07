#include <iostream>

using std::cin;
using std::endl;
using std::cout;

static const int maxn{50};
char symbols[maxn];

void
init()
{
    for (int i{0}; i < maxn; ++i) {
        symbols[i] = i + (i >= 26 ? 'a'-26 : 'A');
    }
}

int
main()
{
    init();
    int n;
    int c{0};
    while (cin >> n) {
        cout << 2 << ' ' << n << ' ' << n << endl;;
        for (int i{0}; i < n; ++i) {
            for (int j{0}; j < n; ++j) {
                cout << symbols[i];
            }
            cout << endl;
        }
        cout << endl;
        for (int i{0}; i < n; ++i) {
            for (int j{0}; j < n; ++j) {
                cout << symbols[j];
            }
            cout << endl;
        }
        if (c++) cout << endl;
    }
}
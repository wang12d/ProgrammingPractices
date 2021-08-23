#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::lower_bound;
using std::upper_bound;

int
main()
{
    vector<int> a{1, 2, 3, 3, 3, 3, 4};
    int p; cin >> p;
    auto it = lower_bound(a.begin(), a.end(), p);
    if (it == a.end() || *it != p) {
        cout << -1 << ',' << -1 << endl;
    } else {
        auto up = upper_bound(a.begin(), a.end(), p);
        auto i{it-a.begin()}, offset{up-a.begin()};
        cout << i << ' ' << offset-1 << endl;
    }
}
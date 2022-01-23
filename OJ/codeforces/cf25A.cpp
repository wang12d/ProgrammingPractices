#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int
main(int argc, char** argv)
{
    int n, m; bool even_multiples{false};
    cin >> n; int last_even_idx{0}, last_odd_idx{0};
    for (int i{1}; i <= n; ++i) {
        cin >> m;
        if (m & 1) {
            last_odd_idx = i;
        } else {
            if (last_even_idx > 0) {
                even_multiples = true;
            }
            last_even_idx = i;
        }
    }
    cout << (even_multiples ? last_odd_idx : last_even_idx) << endl;
}
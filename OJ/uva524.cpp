#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::bitset;
using std::begin;
using std::next;

static const int MAXVAL{17};
static constexpr const int MAXS{2*MAXVAL+1};
int n;

static bool 
isPrime(int t_n)
{
    if (t_n == 1) {
        return false;
    }
    if (t_n == 2) {
        return true;
    }
    if (t_n % 2 == 0) {
        return false;
    }
    for (int i{3}; i*i <= t_n; i += 2) {
        if (t_n % i == 0) {
            return false;
        }
    }
    return true;
}

void
backtracking(int current, vector<int>& path, bitset<MAXS>& isprime, bitset<MAXVAL>& vis)
{
    if (current == n && isprime.test(path[current-1]+path[0])) {
        for_each(begin(path), next(begin(path), current), [j=0](const int& i) mutable {
            if (j++) {
                cout << ' ';
            }
            cout << i;
        });
        cout << endl;
    } else {
        for (int i{2}; i <= n; ++i) {
            if (!vis.test(i) && isprime.test(path[current-1]+i)) {
                path[current] = i;
                vis.flip(i);
                backtracking(current+1, path, isprime, vis);
                vis.flip(i);
            }
        }
    }
}

int
main(int argc, char** argv)
{
    bitset<MAXS> isprime;
    bitset<MAXVAL> vis;
    for (int i{0}; i <= MAXS; ++i) {
        if (isPrime(i)) {
            isprime.flip(i);
        }
    }

    vector<int> path(MAXVAL, 1);
    int c{1};
    while (std::cin >> n) {
        if (c > 1) {
            cout << endl;
        }
        cout << "Case " << c++ << ':' << endl;
        backtracking(1, path, isprime, vis);
    }
}
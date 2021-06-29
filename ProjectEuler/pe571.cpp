#include <bits/stdc++.h>
#include "Toolbox.h"

using std::vector;
using std::next_permutation;
using std::cout;
using std::endl;

bool checkBase(ulong, ulong);

int
main(int argc, char** argv)
{
    ulong base{12};
    if (argc > 1) sscanf(argv[1], "%lu", &base);
    vector<ulong> digits{1, 0};
    for (ulong i = 2; i < base; ++i) {
        digits.push_back(i);
    }
    ulong res{0}; ulong find{0};
    do {
        ulong cp{0}; ulong cnt{base};
        for (auto &d: digits) {
            cp *= base;
            cp += d;
        }
        bool flag = true;
        for (ulong b = base-1; b >= 2; --b) {
            if (!checkBase(cp, b)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            res += cp;
            find++;
        }
    } while(find < 10 && next_permutation(digits.begin(), digits.end()));
    cout <<  res << endl;
}

bool
checkBase(ulong n, ulong base)
{
    ulong maxn{(1LU << base) - 1};
    ulong flag{0};
    while (n) {
        ulong rem = n % base;
        flag |= (1 << rem);
        n /= base;
    }
    return flag == maxn;
}
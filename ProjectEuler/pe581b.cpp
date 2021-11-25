#include <iostream>
#include "Toolbox.h"
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::vector;
using ull = unsigned long long;

int
main()
{
    const static int maxp{47};
    vector<int> primes{Toolbox<int>::findPrimes(maxp)};
    vector<int> pointers(primes.size(), 0);
    vector<ull> smooth{1}; ull maxv{static_cast<ull>(1e13)};
    for (int i{1}; ; ++i) {
        int ptr{0}; ull minv{INT64_MAX};
        for (const auto& p: primes) {
            minv = std::min<ull>(minv, p*smooth[pointers[ptr]]);
            ptr++;
        }
        if (minv >= maxv || minv < smooth.back()) {
            break;
        }
        smooth.emplace_back(minv);
        ptr = 0;
        for (const auto& p: primes) {
            if (minv % p == 0) {
                pointers[ptr]++;
            }
            ptr++;
        }
    }
    ull ans{0}; auto sz{smooth.size()-1};
    for (auto i{0}; i < sz; ++i) { 
        if (smooth[i+1] == smooth[i]+1) {
            ans += smooth[i];
        }
    }
    cout << ans << endl;
}
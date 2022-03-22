#include <bits/stdc++.h>
#include "Toolbox.h"


using namespace std;
using ull = unsigned long long;
using tll = Toolbox<ull>;


int
main(int argc, char** argv)
{
    tll::timer();
    ull N{static_cast<ull>(1e6)};
    if (argc > 1) {
        sscanf(argv[1], "%llu", &N);
    }
    ull val; ull ans{1};
    vector<ull> vals;

    for (ull y{1};y*y*(y+1)*(y+1) <= N; ++y) {
        for (ull x{1}; (val=x*(x+1)*y*(y+1)) <= N; ++x) {
            vals.emplace_back(val);
        }
    }
    sort(begin(vals), end(vals));

    
    for (auto it{begin(vals)+1}; it != end(vals); ++it) {
        if ((*it) != *(it-1)) {
            ++ans;
        }
    }
    cout << ans << endl;
    tll::timeCost();
}
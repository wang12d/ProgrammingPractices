#include "Toolbox.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::sort;

long avoidOverflowMod(long, long, long);

int
main(int argc, char** argv)
{
    Toolbox<long>::timer();
    const static long prime = 4503599627370517L;
    const static long m = 1504170715041707L;
    const static long threshold = 2e7;
    static long reverse_modolu = 0;
    long b; long res = 0; long prev_n = 0;
    Toolbox<long>::extendGCD(m, prime, &reverse_modolu, &b);
    if (reverse_modolu < 0) reverse_modolu += prime;
    long eulercoin = m; long index = 1;
    for (; eulercoin > threshold; ++index) {
        long mod = avoidOverflowMod(m, index, prime);
        if (mod <= eulercoin) {
            eulercoin = mod;
            res += eulercoin;
        }
    }
    vector<pair<long, long>> coin_index;
    for (long i = 1; i < eulercoin; ++i) {
        long nextIndex = avoidOverflowMod(reverse_modolu, i, prime);
        coin_index.push_back({nextIndex, i});
    }
    sort(coin_index.begin(), coin_index.end());
    for (auto &p: coin_index) {
        if (p.first > index && eulercoin > p.second) {
            eulercoin = p.second;
            index = p.first;
            res += eulercoin;
        }
    }
    cout << res << endl;
    Toolbox<long>::timeCost();
}

long
avoidOverflowMod(long base, long exp, long mod)
{
    long res = 0;
    while (exp) {
        if (exp & 1) {
            res = (res + base) % mod;
        }
        base = (base + base) % mod;
        exp >>= 1;
    }
    return res;
}
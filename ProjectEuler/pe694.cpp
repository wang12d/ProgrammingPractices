#include "Toolbox.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using std::vector;
using std::cout;
using std::endl;
using std::for_each;
using std::sort;
using std::set;

const static long maxn = 1e18;
bool judge(__int128_t);

int
main(int argc, char** argv)
{
    vector<long> primes{Toolbox<long>::findPrimes(static_cast<long>(1e6))};
    long res = maxn;     vector<long> primes_cp{primes.begin(), primes.end()};
    for_each(primes.begin(), primes.end(), [](long& n){n = n*n*n;});
    for (auto i = 0; i < primes_cp.size(); ++i) {
        __int128_t m = primes[i];
        while (m*static_cast<__int128_t>(primes_cp[i]) < maxn) {
            m = m * primes_cp[i];
            primes.push_back(m);
        }
    }
    set<long> dup;
    sort(primes.begin(), primes.end());
    size_t size = primes.size();
    for (size_t i = 0; i < size; ++i) {
        res += maxn / primes[i];
        dup.insert(primes[i]);
    }
    for (size_t i = 0; i < size; ++i) {
        __int128_t p = primes[i];
        for (size_t j = i+1; j < size; ++j) {
            __int128_t mul = p*primes[j];
            if (judge(mul)) break;
            if(dup.find(mul) == dup.end()) {
                dup.insert(mul);
                res += maxn / mul;
            }
        }
    }
    for (size_t i = 0; i < size; ++i) {
        __int128_t mul = primes[i];
        for (size_t j = i+1; j < size; ++j) {
            mul *= primes[j]; if(judge(mul))  {mul /= primes[j]; break;}
            for (size_t k = j+1; k < size; ++k) {
                mul *= primes[k]; if (judge(mul)) {mul /= primes[k];break;}
                if (dup.find(mul) == dup.end()){
                    res += maxn / mul;
                    dup.insert(mul);
                }
                mul /= primes[k];
            }
            mul /= primes[j];
        }
    }
    for (size_t i = 0; i < size; ++i) {
        __int128_t mul = primes[i];
        for (size_t j = i+1; j < size; ++j) {
            mul *= primes[j]; if (judge(mul)) {mul /= primes[j];break;}
            for (size_t k = j+1; k < size; ++k) {
                mul *= primes[k]; if(judge(mul)) {mul /= primes[k];break;}
                for (size_t v=k+1; v < size; ++v) {
                    mul *= primes[v]; if (judge(mul)) {mul /= primes[v]; break;}
                    if (dup.find(mul) == dup.end()){
                        res += maxn / mul;
                        dup.insert(mul);
                    }
                    mul /= primes[v];
                }
                mul /= primes[k];
            }
            mul /= primes[j];
        }
    }
    for (size_t i = 0; i < size; ++i) {
        __int128_t mul = primes[i];
        for (size_t j = i+1; j < size; ++j) {
            mul *= primes[j]; if (judge(mul)) {mul /= primes[j]; break;}
            for (size_t k = j+1; k < size; ++k) {
                mul *= primes[k]; if(judge(mul)) {mul /= primes[k]; break;}
                for (size_t v=k+1; v < size; ++v) {
                    mul *= primes[v]; if (judge(mul)) {mul /= primes[v];break;}
                    for (size_t u=v+1; u < size; ++u) {
                        mul *= primes[u]; if (judge(mul)) {mul /= primes[u];break;}
                        if (dup.find(mul) == dup.end()){
                            res += maxn / mul;
                            dup.insert(mul);
                        }
                        mul /= primes[u];
                    }
                    mul /= primes[v];
                }
                mul /= primes[k];
            }
            mul /= primes[j];
        }
    }
    for (size_t i = 0; i < size; ++i) {
        __int128_t mul = primes[i];
        for (size_t j = i+1; j < size; ++j) {
            mul *= primes[j]; if (judge(mul)) {mul /= primes[j]; break;}
            for (size_t k = j+1; k < size; ++k) {
                mul *= primes[k]; if(judge(mul)) {mul /= primes[k]; break;}
                for (size_t v=k+1; v < size; ++v) {
                    mul *= primes[v]; if (judge(mul)) {mul /= primes[v];break;}
                    for (size_t u=v+1; u < size; ++u) {
                        mul *= primes[u]; if (judge(mul)) {mul /= primes[u];break;}
                        for (size_t o=u+1; o < size; ++o) {
                            mul *= primes[o]; if(judge(mul)) {mul /= primes[o];break;}
                            if (dup.find(mul) == dup.end()){
                                res += maxn / mul;
                                dup.insert(mul);
                            }
                            mul /= primes[o];
                        }
                        mul /= primes[u];
                    }
                    mul /= primes[v];
                }
                mul /= primes[k];
            }
            mul /= primes[j];
        }
    }
    for (size_t i = 0; i < size; ++i) {
        __int128_t mul = primes[i];
        for (size_t j = i+1; j < size; ++j) {
            mul *= primes[j]; if (judge(mul)) {mul /= primes[j]; break;}
            for (size_t k = j+1; k < size; ++k) {
                mul *= primes[k]; if(judge(mul)) {mul /= primes[k]; break;}
                for (size_t v=k+1; v < size; ++v) {
                    mul *= primes[v]; if (judge(mul)) {mul /= primes[v];break;}
                    for (size_t u=v+1; u < size; ++u) {
                        mul *= primes[u]; if (judge(mul)) {mul /= primes[u];break;}
                        for (size_t o=u+1; o < size; ++o) {
                            mul *= primes[o]; if(judge(mul)) {mul /= primes[o];break;}
                            for (size_t x=o+1; x < size; ++x) {
                                mul *= primes[x]; if (judge(mul)) {mul /= primes[x]; break;}
                                if (dup.find(mul) == dup.end()){
                                    res += maxn / mul;
                                    dup.insert(mul);
                                }
                                mul /= primes[x];

                            }
                            mul /= primes[o];
                        }
                        mul /= primes[u];
                    }
                    mul /= primes[v];
                }
                mul /= primes[k];
            }
            mul /= primes[j];
        }
    }
    cout << res << endl;
}

bool
judge(__int128_t n)
{
    return n > maxn;
}
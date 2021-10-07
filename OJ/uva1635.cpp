#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::pair;

using pp = pair<int,int>;

static const int maxn{static_cast<int>(1e6)+1};

static vector<bool> isprime(maxn, true);

vector<int>// Found all 
findPrimes(int m)
{
    int sqrt{static_cast<int>(floor(sqrtf64(static_cast<double>(m))))};
    vector<int> primes;
    for (long i{2}; i <= sqrt; ++i) {
        int prev{m};
        while (m % i == 0) {
            m /= i;
        }
        if (prev != m) {
            primes.emplace_back(i);
        }
    }
    if (m > 1) {
        primes.emplace_back(m);
    }
    return primes;
}

int
main()
{
    int n, m;
    static int cnt{0};
    static vector<pp> mprimeFactors;
    static vector<pp> nprimeFactors;
    static vector<bool> irrelevant(maxn, true);
    static vector<int> ans;
    while (cin >> n >> m) {
        mprimeFactors.clear();
        ans.clear();
        nprimeFactors.clear();
        std::fill(irrelevant.begin(), irrelevant.end(), true);
        cnt = n; --n;
        if (m > 1) {
            cnt -= n ? 2 : 1;
            irrelevant[0] = irrelevant[n] = false;
        }
        auto primes{findPrimes(m)};
        for (auto &p: primes) {
            if (p > m) {
                break;
            }
            int ptr{0};
            while (m % p == 0) {
                m /= p;
                ptr++;
            }
            mprimeFactors.emplace_back(p, ptr);
        }
        for (auto &p: mprimeFactors) {
            int cpn{n}; int cnt{0};
            int cp{p.first};
            while (cpn / cp) {
                cnt += cpn / cp;
                cp *= p.first;
            }
            nprimeFactors.emplace_back(p.first, cnt);
        }
        for (int k{1}; k < n; ++k) {
            int downk{k};
            int upk{n-k}; int ptr{0};
            for (auto &p: mprimeFactors) {
                int tk{downk}; int pcnt{0};
                int cp{p.first};
                while (tk / cp) {
                    pcnt += tk / cp;
                    cp *= p.first;
                }
                tk = upk;
                cp = p.first;
                while (tk / cp) {
                    pcnt += tk / cp;
                    cp *= p.first;
                }
                if (pcnt+p.second > nprimeFactors[ptr++].second) {
                    irrelevant[k] = false;
                    cnt--;
                    break;
                }
            }
        }
        cout << cnt << endl;
        if (cnt) {
            for (int i{0}; i <= n; ++i) {
                if (irrelevant[i]) {
                    cnt--;
                    cout << i+1;
                    if (cnt) {
                        cout << ' ';
                    }
                }
            }
        }
        cout << endl;
    }
}
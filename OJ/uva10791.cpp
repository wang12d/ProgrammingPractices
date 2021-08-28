#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::endl;
using std::cout;

static const int maxn{(1<<16)+1};

int
main()
{
    vector<int> notprime(maxn, false);
    notprime[0] = notprime[1] = true;
    vector<int> primes;
    for (auto i{2}; i*i < maxn; ++i) {
        if (!notprime[i]) {
            for (auto j{i*i}; j < maxn; j += i) {
                notprime[j] = true;
            }
        }
    }
    for (auto i{2}; i < maxn; ++i) {
        if (!notprime[i]) {
            primes.push_back(i);
        }
    }
    unsigned n; int c{0};
    while (cin >> n && n) {
        unsigned curr{0}; 
        int cnt{0};
        if (n == 1) {
            curr = 2; cnt = 2;
        } else {
            for (auto &p: primes) {
                unsigned cp{1}; if (p > n) break;
                while (n % p == 0) {
                    cp *= p;
                    n /= p;
                }
                if (cp != 1) {
                    curr += cp; cnt++;
                }
            }
        }
        cout << "Case " << ++c << ": ";
        if (n != 1) curr += n;
        if (cnt > 1 || (cnt == 1 && n != 1)) {
            cout << curr << endl;
        } else {
            cout << curr+1 << endl;
        }
    }
}
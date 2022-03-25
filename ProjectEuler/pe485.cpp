#include <bits/stdc++.h>
#include "Toolbox.h"


using namespace std;
using ull = unsigned long long;
using ll = long long;
using tull = Toolbox<ull>;
using tll = Toolbox<ll>;

const ull MAXN{static_cast<ull>(1e8)};
const ull MAXK{static_cast<ull>(1e5)};

ull
sumOfMaxKElement(vector<ull>& numberDivisors, ull k)
{
    deque<ull> q;
    ull i{1};
    for (; i <= k; ++i) {
        while (!q.empty() && numberDivisors.at(q.back()) < numberDivisors.at(i)) {
            q.pop_back();
        }
        q.push_back(i);
    }

    ull ans{0};
    for (; i < numberDivisors.size(); ++i) {
        ans += numberDivisors.at(q.front());
        while (!q.empty() && i - q.front() >= k) {
            q.pop_front();
        }

        while (!q.empty() && numberDivisors.at(q.back()) < numberDivisors.at(i)) {
            q.pop_back();
        }
        q.push_back(i);
    }

    ans += numberDivisors.at(q.front());
    return ans;
}

ull
divPower(ull n, ull p)
{
    ull ans{1};
    while (n % p == 0) {
        n /= p; ++ans;
    }
    return ans;
}

int
main(int argc, char** argv)
{
    tull::timer();

    ull n{MAXN}, k{MAXK};
    if (argc > 2) {
        sscanf(argv[1], "%llu", &n);
        sscanf(argv[2], "%llu", &k);
    }

    vector<ull> numberDivisors(n+1, 1);
    vector<ull> primes{tull::findPrimes(n)};

    for (auto& p: primes) {
        for (ull i{p}; i <= n; i += p) {
            numberDivisors.at(i) *= divPower(i, p);
        }
    }
    cout << sumOfMaxKElement(numberDivisors, k) << endl;

    tull::timeCost();
}
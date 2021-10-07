#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::generate;

static const int maxn{50000 + 1};

vector<int>
generatePhi()
{
    vector<bool> isprime(maxn, true);
    isprime[0] = isprime[1] = false;
    vector<int> phi(maxn, 0);
    generate(std::begin(phi), std::end(phi), [n = 0]() mutable {
        return n++;
    });
    for (int i{2}; i < maxn; ++i) {
        if (isprime[i]) {
            phi[i] = i-1;
            for (int j{i*2}; j < maxn; j += i) {
                phi[j] = phi[j] * (i-1) / i;
                isprime[j] = false;
            }
        }
    }
    return phi;
}

int
main()
{
    auto phi{generatePhi()};
    int N;
    while (cin >> N && N) {
        int ans{1};
        for (int i{2}; i <= N; ++i) {
            ans += 2*phi[i];
        }
        cout << ans << endl;
    }
}
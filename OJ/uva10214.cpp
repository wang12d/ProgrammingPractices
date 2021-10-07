#include <iostream>
#include <vector>
#include <iomanip>


using ld = long double;
using ull = unsigned long long;

static const int maxa{2000+1};
std::vector<ull> phi(maxa, 0);

ull
gcd(ull a, ull b)
{
    if (a) {
        return gcd(b%a, a);
    }
    return b;
}

void
init()
{
    ull cnt{0};
    for (auto &x: phi) {
        x = cnt++;
    }
    phi[0] = 0;
    phi[1] = 1;
    for (int i{2}; i <= maxa; ++i) {
        if (phi[i] == i) {
            for (int j{i}; j <= maxa; j+=i) {
                phi[j] = phi[j]*(i-1) / i;
            }
        }
    }
}

int
main()
{
    ull a, b;
    init();
    while (std::cin >> a >> b && a) {
        ull K{0};
        for (int i{1}; i <= a; ++i) {
            K += b / i * phi[i];
            auto rem{b % i};
            for (int j{1}; j <= rem; ++j) {
                if (gcd(i, j) == 1) {
                    ++K;
                }
            }
        }
        K = 4*K+4;
        ld dK{static_cast<ld>(K)};
        ld dN{static_cast<ld>(((a<<1)+1)*((b<<1)+1))-1};
        std::cout << std::fixed << std::setprecision(7) << dK / dN << std::endl;
    }
}
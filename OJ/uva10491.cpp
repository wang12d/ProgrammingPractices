#include <iostream>
#include <iomanip>


using ld = long double;

ld
calculateProb(ld ncrows, ld ncars, ld nshow)
{
    ld total{ncrows+ncars};
    ld aftertotal{total-nshow-1};
    return ncrows * ncars / aftertotal / total + ncars * (ncars-1) / total / aftertotal;
}

int
main()
{
    ld crows, cars, show;
    while (std::cin >> crows >> cars >> show) {
        std::cout << std::setprecision(5) << std::fixed;
        std::cout << calculateProb(crows, cars, show) << std::endl;
    }
}
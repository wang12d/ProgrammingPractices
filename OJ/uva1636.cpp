#include <iostream>
#include <vector>

using std::string;

struct fraction
{   // fraction x/y;
    int x, y;
};


string
compFraction(fraction a, fraction b)
{
    int x{a.x*b.y}; int y{a.y*b.x};
    if (x > y) {
        return "SHOOT";
    } else if (x == y) {
        return "EQUAL";
    } else {
        return "ROTATE";
    }
}

int
main()
{
    string line;
    while (getline(std::cin, line)) {
        int n{static_cast<int>(line.size())};
        int rotate{0}; int notrotate{0};
        for (auto &c: line) {
            if (c == '1') {
                rotate++;
            }
        }
        for (int j{0}; j < n; ++j) {
            if (line[j] == '0' && line[(j+1) % n] == '1') {
                notrotate++;
            }
        }
        std::cout << compFraction({rotate, n}, {notrotate, n-rotate}) << std::endl;
    }
}
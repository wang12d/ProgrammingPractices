#include <iostream>

int
main()
{
    int h, w;
    std::string line;
    while (std::cin >> h >> w) {
        int ans{0};
        for (int i{0}; i < h; ++i) {
            std::cin >> line;
            bool inpolygon{false};
            for (int j{0}; j < w; ++j) {
                if (line.at(j) == '/' || line.at(j) == '\\') {
                    inpolygon = !inpolygon;
                    ++ans;
                } else if (inpolygon) {
                    ans += 2;
                }
            }
        }
        std::cout << (ans >> 1) << std::endl;
    }
}
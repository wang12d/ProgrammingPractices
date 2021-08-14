#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int
main(int argc, char** argv)
{
    int k;
    while (cin >> k) {
        int doubleK{2*k};
        vector<std::string> outputs;
        int cnt{0};
        for (int y{k+1}; y <= doubleK; ++y) {
            if ((k*y) % (y-k) == 0) {
                int x{k*y/(y-k)};
                if (x >= y) {
                    cnt++;
                    outputs.push_back(std::string{"1/" + std::to_string(k) + " = 1/" + std::to_string(x) + " + 1/" + std::to_string(y)});
                }
            }
        }
        cout << cnt << endl;
        std::for_each(outputs.begin(), outputs.end(), [](const std::string& s) {
            cout << s << endl;
        });
    }
}
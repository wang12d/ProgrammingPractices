#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void
flipFlapjacks(int first, int tail, int size, vector<int>& flapJacks, int& cnt)
{
    int maxLoc{std::max_element(flapJacks.begin(), flapJacks.begin()+tail) - flapJacks.begin()};
    if (maxLoc == tail-1) {
        return;
    } 
    if (maxLoc != 0) {
        if (cnt) cout << ' ';
        cout << size - maxLoc; cnt++;
        std::reverse(flapJacks.begin(), flapJacks.begin()+maxLoc+1);
    }
    std::reverse(flapJacks.begin(), flapJacks.begin()+tail);
    if (cnt) cout << ' ';
    cout << size-tail+1; cnt++;
}

int
main()
{
    std::string s;
    int ptr{0}; vector<int> flapJacks(30+1, 0);
    while (std::getline(cin, s)) {
        cout << s << endl;
        std::stringstream ss{s};
        int m; ptr = 0;
        while (ss >> m)  {
            flapJacks[ptr++] = m;
        }
        int cnt{0};
        for (int i{0}; i < ptr; ++i) {
            flipFlapjacks(0, ptr-i, ptr, flapJacks, cnt);
        }
        if (cnt) cout << ' ';
        cout << 0 << endl;
    }
}
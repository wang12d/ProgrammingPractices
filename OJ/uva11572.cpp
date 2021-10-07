#include <unordered_map>
#include <vector>
#include <iostream>

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::unordered_map;

int
main()
{
    int T;
    cin >> T;
    unordered_map<int, int> pp;
    vector<int> snowflakes;
    while (T--) {
        int n;
        cin >> n; int v;
        snowflakes.clear();
        pp.clear();
        for (int i{0}; i < n; ++i) {
            cin >> v;
            snowflakes.emplace_back(v);
        }
        int right{0}, left{0};
        size_t ans{0};
        while (right < n) {
            if (!pp.count(snowflakes[right])) {
                pp.insert({snowflakes[right], right});
                ans = std::max(ans, pp.size());
            } else {
                for (; left < pp[snowflakes[right]]; ++left) {
                    pp.erase(snowflakes[left]);
                }
                ++left;
                pp[snowflakes[right]] = right;
            }
            right++;
        }
        cout << ans << endl;
    }
}
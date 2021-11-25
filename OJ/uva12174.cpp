#include <iostream>
#include <vector>
#include <numeric>

using std::accumulate;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

const int maxn{100000};
vector<int> count(maxn);
vector<bool> canShuffle(maxn, false);
vector<int> numbers(maxn);

int
main(int argc, char** argv)
{
    int T;
    int s, n;
    cin >> T;
    while (T--) {
        cin >> s >> n;
        for (int i{0}; i < n; ++i) {
            cin >> numbers.at(i);
        }
        int bound{s+n};
        int diffCount{0};
        std::fill(count.begin(), count.begin()+s+1, 0);
        std::fill(canShuffle.begin(), canShuffle.begin()+s, true);
        for (int i{0}; i < bound; ++i) {
            if (i < n) {
                if (++count.at(numbers.at(i)) == 1) {
                    diffCount++;
                }
            }
            if (i >= s) {
                if (--count.at(numbers.at(i-s)) == 0) {
                    diffCount--;
                }
            }
            if (std::min(n-1, i) - std::max(i-s, -1) != diffCount) {
                canShuffle.at(i%s) = false;
            }
        }
        int ans{0};
        for (int i{0}; i < s; ++i) {
            if (canShuffle.at(i)) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}
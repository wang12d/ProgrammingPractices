#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <cassert>

using std::sort;
using std::vector;
using std::accumulate;
using std::priority_queue;
using std::cout;
using std::cin;
using std::endl;

using ll = long long;
static const ll maxn{100000};

int
main(int argc, char** argv)
{
    int N, n;
    priority_queue<int, vector<int>, std::greater<int>> pq;
    while (cin >> N && N) {
        ll ans{0};
        ll s{0};
        for (int i{0}; i < N; ++i) {
            cin >> n;
            pq.push(n);
        }
        while (pq.size() != 1) {
            s = pq.top(); pq.pop();
            s += pq.top(); pq.pop();
            ans += s;
            pq.push(s);
        }
        assert(pq.size() == 1);
        pq.pop();
        cout << ans << endl;
    }
}
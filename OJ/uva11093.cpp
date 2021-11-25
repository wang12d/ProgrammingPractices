#include <iostream>
#include <vector>

using ll = long long;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

const ll maxn{100000};

int
main(int argc, char** argv)
{
    ll T;
    ll N;
    cin >> T;
    vector<ll> P(maxn), Q(maxn);
    for (ll c{1}; c <= T; ++c) {
        cin >> N;
        for (ll i{0}; i < N; ++i) {
            cin >> P[i];
        }
        for (ll i{0}; i < N; ++i) {
            cin >> Q[i];
        }
        ll total{0}, required{0};
        ll ans{0};
        for (ll i{0}; i < N; ++i) {
            total += P[i] - Q[i];
            required += P[i] - Q[i];
            if (required < 0) {
                ans = i+1;
                required = 0;
            }
        }
        if (total < 0) {
            printf("Case %d: Not possible\n", c);
        } else {
            printf("Case %d: Possible from station %d\n", c, ans+1);
        }
    }
}
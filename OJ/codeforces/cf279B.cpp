#include <bits/stdc++.h>

using namespace std;

int
main()
{
    using ull = unsigned long long;
    ull n, t;
    cin >> n >> t;
    vector<ull> arr(n+1, 0);
    for (int i{1}; i <= n; ++i) {
        cin >> arr.at(i);
        arr.at(i) += arr.at(i-1);
    }
    ull ans{0};
    for (int i{0}; i < n; ++i) {
        ans = max(ans, static_cast<ull>(upper_bound(begin(arr)+i, end(arr), arr.at(i)+t)-(begin(arr)+i))-1);
    }
    cout << ans << endl;
}
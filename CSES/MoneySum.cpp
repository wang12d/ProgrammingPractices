#include <bits/stdc++.h>

using namespace std;

int
main(int argc, char** argv)
{
    static const int maxn = 100;
    set<int> dp;
    int n; cin >> n;
    vector<int> nums(maxn, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    for (int i = 0; i < n; ++i) {
        set<int> tmp = dp;
        for (auto &d: tmp) {
            int p = d + nums[i];
            dp.insert(p);
        }
        dp.insert(nums[i]);
    }
    cout << dp.size() << endl;
    auto it = dp.begin(); cout << *it;
    auto end = dp.end();
    for (++it; it != end; ++it) {
        cout << ' ' << *it;
    }
    cout << endl;
}
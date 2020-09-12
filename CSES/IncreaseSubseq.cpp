#include <bits/stdc++.h>

using namespace std;

int
main(int argc, char** argv)
{
    static const int maxn = 2e5;    
    int n; cin >> n;
    vector<int> arr(maxn, 0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> dp;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        if (it == dp.end()) dp.push_back(arr[i]);
        else *it = arr[i];
    }
    cout << dp.size() << endl;
}
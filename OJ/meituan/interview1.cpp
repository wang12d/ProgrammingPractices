#include <iostream>
#include <algorithm>
#include <vector>

using std::next_permutation;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int
main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i{0}; i < n; ++i) {
        cin >> arr[i];
    }
    int cnt{0};
    vector<vector<int>> ans;
    std::sort(arr.begin(), arr.end());
    do
    {
        ans.push_back(arr);
    } while (next_permutation(arr.begin(), arr.end()));

    cout << ans.size() << endl;
    for (auto &a: ans) {
        for (auto i{0}; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << endl;
    }
}
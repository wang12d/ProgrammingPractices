#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using std::unordered_map;
using std::sort;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::swap;
using std::queue;

int
main()
{
    int n;
    cin >> n;
    unordered_map<int, queue<int>> m;
    vector<int> arr(n, 0);
    for (int i{0}; i < n; ++i) {
        cin >> arr[i];
        m[arr[i]].push(i);
    }
    vector<int> raw{arr.begin(), arr.end()};
    sort(arr.begin(), arr.end());
    int ans{0};
    for (int i{0}; i < n; ++i) {
        if (raw[i] != arr[i]) {
            int cp{raw[i]};
            std::swap(raw[i], raw[m[arr[i]].front()]);
            m[cp].pop();
            m[cp].push(m[arr[i]].front());
            m[arr[i]].pop();
            ans++;
        }
    }
    cout << ans << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int
main(int argc, char** argv)
{
    int n;
    cin >> n;
    vector<long long> arr(n, 0);
    vector<long long> curr(n+1, 0);
    for (int i{0}; i < n; ++i) {
        cin >> arr[i];
        curr[i+1] = curr[i] + arr[i];
    }
    int t;
    cin >> t;
    int a, b, c;
    for (int i{0}; i < t; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            cout << curr[c]-curr[b-1] << endl;
        } else if (a == 2) {
            long long k{curr[c]-curr[b-1]}; long long ans{0};
            for (int j{b-1}; j < c; ++j) {
                long long tmp{k-arr[j]};
                ans += tmp * tmp;
            }
            cout << ans << endl;
        } else {
            cout << *std::max_element(arr.begin()+b-1, arr.begin()+c) << endl;
        }
    }
}
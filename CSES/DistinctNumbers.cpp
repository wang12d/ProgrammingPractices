#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    static int n;
    cin >> n;
    vector<int> vec(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int prev = -1; int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (prev != vec[i]) {
            prev = vec[i];
            ans++;
        }
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>

using namespace::std;

int
main(int argc, char** argv)
{
    int T, n;
    static const int maxn = 1e5;
    vector<int> A(maxn, 0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        long long res = 1;
        int prev = 1; int current = prev;
        for (int i = 1; i < n; ++i) {
            if (A[i] >= A[i-1]) {
                current += prev;
            }
            else {
                current = 1;
            }
            prev = current;
            res += current;
            current = 1;
        }
        cout << res << endl;
    }
}

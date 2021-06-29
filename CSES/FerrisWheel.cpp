#include <bits/stdc++.h>

using namespace std;

int
main(int argc, char** argv)
{
    static int n, x;
    cin >> n >> x;
    vector<int> A(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int right = n-1, left = 0;
    int ans = 0; int cur = 0;
    while (right >= left) {
        if (right == left) {ans++; break;}
        cur = A[right];
        if (right > left && cur+A[left] <= x) {
            cur += A[left];
            left++;
        }
        ans++; right--;
    }
    cout << ans << endl;
}
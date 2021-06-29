#include <bits/stdc++.h>

using namespace std;

int
main(int argc, char** argv)
{
    static int n, m;
    cin >> n >> m;
    vector<int> A(n, 0);
    vector<bool> B(n, false);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    unordered_map<int,int> memo;
    int p;
    for (int i = 0; i < m; ++i) {
        cin >> p;
        auto j = upper_bound(A.begin(), A.end(), p) - A.begin();
        if (j==n || A[j] > p)--j;
        int prev = j;
        if (memo.count(prev)) j = memo[prev];
        while (j>=0 && B[j])--j;
        if (j >= 0) memo[prev] = j;
        if (j >= 0) {
            B[j] = true;
            cout << A[j] << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}
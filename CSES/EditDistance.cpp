#include <bits/stdc++.h>

using namespace std;

int
search(string& a, string& b, int atail, int btail, vector<vector<int>>& dp)
{
    if (atail < 0 && btail < 0) return 0;
    if (atail < 0) return btail+1;
    if (btail < 0) return atail+1;
    if (dp[atail][btail] != -1) return dp[atail][btail];
    if (a[atail] == b[btail]) {
        return dp[atail][btail] = search(a, b, atail-1, btail-1, dp);
    }
    else {
        return dp[atail][btail] = 1 + min(search(a, b, atail-1, btail, dp), min(search(a, b, atail, btail-1, dp), search(a, b, atail-1, btail-1, dp)));
    }
}

int
main(int argc, char** argv)
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << search(a, b, n-1, m-1, dp) << endl;
}
#include <bits/stdc++.h>

using namespace std;

int
main(int argc, char** argv)
{
    static int n, m, k;
    cin >> n >> m >> k;
    vector<int> apps(n, 0);
    vector<int> aparts(m, 0);
    for (int i = 0; i < n; ++i) {
        cin >> apps[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> aparts[i];
    }
    sort(apps.begin(), apps.end());
    sort(aparts.begin(), aparts.end());
    int ans = 0; int app_ind = 0, apart_ind = 0;
    while (app_ind < n && apart_ind < m) {
        if (apps[app_ind] < aparts[apart_ind]-k) {
            app_ind++;
        }
        else if (apps[app_ind] > aparts[apart_ind]+k) {
            while (apart_ind< m && apps[app_ind] > aparts[apart_ind]+k) apart_ind++;
        }
        else {
            app_ind++; apart_ind++; ans++;
        }
    }
    cout << ans << endl;
}
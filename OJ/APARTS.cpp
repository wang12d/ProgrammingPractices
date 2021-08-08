#include <bits/stdc++.h>

using namespace std;

int
main(int argc, char** argv)
{
    static const int maxn = 1e3+2;
    static const int maxm = 1e3+2;
    vector<vector<int>> windows(maxn, vector<int>(maxm, 0));
    vector<vector<int>> print(maxn, vector<int>(maxm, 0));
    int T, N, M;
    cin >> T;
    while (T--) {
        cin >> N >> M; int n;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                cin >> windows[i][j];
            }
        }
        for (int i = 1; i <= M; ++i) {
            print[1][i] = windows[1][i];
        }
        for (int i = 2; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                print[i][j] = max(windows[i][j], max(print[i-1][j], max(print[i-1][j-1], print[i-1][j+1])));
            }
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (print[i][j] > windows[i][j]) cout << 0;
                else cout << 1;
            }
            cout << endl;
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                windows[i][j] = 0;
                print[i][j] = 0;
            }
        }
    }
}
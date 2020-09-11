#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Matrix = vector<vector<ll>>;

static const ll MOD = 1e9+7;

void
mul_matrix(Matrix& a, Matrix b)
{
    for (int i = 0; i < 2; ++i) {
        a[i] ={(a[i][0]*b[0][0]%MOD+a[i][1]*b[1][0]%MOD)%MOD, (a[i][0]*b[0][1]%MOD+a[i][1]*b[1][1]%MOD)%MOD};
    }
}

void
exp_matrix(Matrix& base, ll exp, ll& M)
{
    ll first_mul = ((M%MOD)*(M%MOD))%MOD, second_mul = M%MOD;
    Matrix ans{{1, 0}, {0, 1}};
    while (exp) {
        if (exp & 1) {
            mul_matrix(ans, base);
        }
        mul_matrix(base, base);
        exp >>= 1;
    }
    cout << ((ans[0][0]*first_mul%MOD) + (ans[0][1]*second_mul%MOD))%MOD << endl;
}

int
main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;
    ll N, M;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        if (N == 1) {
            cout << M%MOD << endl;
        }
        else {
            Matrix base{{(M-1)%MOD, (M-1)%MOD}, {1, 0}};
            exp_matrix(base, N-2, M);
        }
    }
}
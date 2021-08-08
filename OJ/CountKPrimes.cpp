#include <bits/stdc++.h>

using namespace std;

int
main(int argc, char** argv)
{
    static const int maxn = 1e5+1;
    static const int maxk = 5+1;
    vector<int> prime_count(maxn, 0);
    vector<bool> primes(maxn, true);
    vector<vector<int>> memo(maxn, vector<int>(maxk, 0));
    for (int i = 2; i < maxn; ++i) {
        if (primes[i]) {
            prime_count[i]++;
            for (int j = 2*i; j < maxn; j += i) {
                prime_count[j]++;
                primes[j] = false;
            }
        }
    }
    for (int i = 2; i < maxn; ++i) {
        if (prime_count[i] <= 5) memo[i][prime_count[i]] = 1;
    }
    
    for (int j = 1; j < maxk; ++j) {
        for (int i = 2; i < maxn; ++i) {
                memo[i][j] += memo[i-1][j];
        }
    }
    int A,B,T,K;
    cin >> T;
    while (T--) {
        cin >> A >> B >> K;
        cout << memo[B][K] - memo[A][K] + (prime_count[A] == K ? 1 : 0) << endl;
    }
}
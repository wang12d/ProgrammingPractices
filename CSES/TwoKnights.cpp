#include <bits/stdc++.h>

using namespace std;

static long long f(long long p) 
{
    return (p-1)*(p+4)*(p*p-3*p+4) / 2;
}

int
main(int argc, char** argv)
{
    static long long n;
    cin >> n;
    for (long long i = 1; i <= n; ++i)
        cout << f(i) << endl;
}
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::string;
using std::cout;
using std::endl;

using ll = long long;

static const int maxn{33 + 1};
vector<string> expectedValues(maxn);

ll
gcd(ll a, ll b)
{
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

ll
lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

string
findExpectedValue(int n)
{
    ll denominator{1};
    for (int i{1}; i <= n; ++i) {
        denominator = lcm(i, denominator);
    }
    ll numerator{0};
    for (int i{1}; i <= n; ++i) {
        numerator += denominator / i;
    }
    numerator = numerator*n;
    ll d{gcd(numerator, denominator)};
    numerator /= d; denominator /= d;
    ll val{0}; ll dd{gcd(val, denominator)};
    val += (numerator / denominator); 
    numerator = numerator % denominator;
    string strval{std::to_string(val)};
    if (denominator != 1) {
        string expectedValue(strval.size()+1, ' ');
        expectedValue.append(std::to_string(numerator));
        expectedValue.push_back('\n');
        expectedValue.append(strval); expectedValue.push_back(' ');
        string denostr{std::to_string(denominator)};
        expectedValue.append(string(denostr.size(), '-'));
        expectedValue.push_back('\n');
        expectedValue.append(string(strval.size()+1, ' '));
        expectedValue.append(denostr);
        return expectedValue;
    }
    return strval;
}

int
main()
{
    for (int i{1}; i < maxn; ++i) {
        expectedValues[i] = findExpectedValue(i);
    }
    int n;
    while (cin >> n) {
        cout << expectedValues[n] << endl;
    }
}
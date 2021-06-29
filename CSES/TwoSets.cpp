#include <bits/stdc++.h>

using namespace std;

int
main(int argc, char** argv)
{
    static long long n;
    cin >> n;
    long long sum = (n * (n + 1)) >> 1;
    if (sum % 2) {
        cout << "NO" << endl;
    }
    else {
        int left, right;
        string one, two;
        int one_len, two_len;
        if (n % 2) {
            one = "1 2 "; two = "3 ";
            one_len = 2; two_len = 1;
            left = 4; right = n;
        }
        else {
            one = ""; two = "";
            one_len = 0; two_len = 0;
            left = 1; right = n;
        }
        while (right > left) {
            one += to_string(left++) + " " + to_string(right--) + " ";
            two += to_string(left++) + " " + to_string(right--) + " ";
            one_len += 2; two_len += 2;
        }
        one = one.substr(0, one.size()-1); two = two.substr(0, two.size()-1);
        cout << "YES" << endl;
        cout << one_len << '\n' << one << endl;
        cout << two_len << '\n' << two << endl;
    }
}
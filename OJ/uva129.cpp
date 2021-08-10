#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::for_each;
using std::begin;
using std::endl;
using std::cout;
using std::cin;

int n;
int L;
int cnt;

bool
dfs(int current, vector<int>& vals)
{
    if (cnt++ == n) {
        int group{1}, cnt{1};
        for_each(begin(vals), next(begin(vals), current), [&](const int& element) mutable {
            if (group % 17 == 0) {
                group = 1;
                cout << endl;
                cnt = 1;
            } else if (cnt % 5 == 0) {
                cnt = 1;
                cout << ' ';
            }
            cnt++;
            if (cnt == 5) group++;
            cout << static_cast<char>(element + 'A');
        });
        cout << endl <<  current << endl;
        return true;
    } else {
        for (int i{0}; i < L; ++i) {
            vals[current] = i;
            bool viable = true;
            for (int j{1}; 2*j <= current+1; ++j) {
                bool containEqual = true;
                for (auto k{0}; k < j; ++k) {
                    if (vals[current-k] != vals[current-k-j]) {
                        containEqual = false;
                        break;
                    }
                }
                if (containEqual) {
                    viable = false;
                    break;
                }
            }
            if (viable) {
                if (dfs(current+1, vals)) {
                    return true;
                }
            }
        }
        return false;
    }
}

int
main(int argc, char** argv)
{
    vector<int> vals(100, 0);
    while (true) {
        cin >> n >> L;
        if (!n && !L) {
            break;
        }
        cnt = 0;
        dfs(0, vals);
    }
}
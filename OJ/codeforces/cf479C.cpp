#include <bits/stdc++.h>

using namespace std;

int
main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> exams(n, {0,0});
    for (auto i{0}; i < n; ++i) {
        cin >> exams.at(i).first >> exams.at(i).second;
    }
    sort(begin(exams), end(exams), [](const auto& a, const auto& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    });
    auto ans{0};
    for (const auto& p: exams) {
        ans = p.second >= ans ? p.second : p.first;
    }
    cout << ans << endl;
}
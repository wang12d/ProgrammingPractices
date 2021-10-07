#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::stringstream;
using std::string;

static const int maxn{200+1};
static int id{0};
vector<vector<int>> tree(maxn);
vector<vector<int>>  d(maxn, vector<int>(2, 0));
vector<vector<bool>> isunique(maxn, vector<bool>(2, 0));
unordered_map<string,int> idmap;

int
getID(string name)
{
    if (!idmap.count(name)) {
        idmap[name] = id++;
    }
    return idmap[name];
}

int
dp(int n, int state)
{
    d[n][state] = state;
    isunique[n][state] = true;
    for (auto& c: tree[n]) {
        if (state == 1) {
            d[n][state] += dp(c, 0);
            if (!isunique[c][0]) {
                isunique[n][state] = false;
            }
        } else {
            d[n][state] += std::max(dp(c, 0), dp(c, 1));
            if (d[c][0] == d[c][1]) {
                isunique[n][state] = false;
            } else if (d[c][0] > d[c][1] && !isunique[c][0]) {
                isunique[n][state] = false;
            } else if (d[c][1] > d[c][0] && !isunique[c][1]) {
                isunique[n][state] = false;
            }
        }
    }
    return d[n][state];
}

int
main(int argc, char** argv)
{
    int n; string a, b;
    while (cin >> n && n) {
        id = 0; idmap.clear();
        for (int i{0}; i < n; ++i) {
            tree[i].clear();
        }
        cin >> a;
        getID(a);
        for (int i{1}; i < n; ++i) {
            cin >> a >> b;
            tree.at(getID(b)).emplace_back(getID(a));
        }
        cout << std::max(dp(0, 0), dp(0, 1));
        if (d[0][0] == d[0][1] || (d[0][1] > d[0][0] && !isunique[0][1]) || (d[0][0] > d[0][1] && !isunique[0][0])) {
            cout << " No";
        } else {
            cout << " Yes";
        }
        cout << endl;
    }
}

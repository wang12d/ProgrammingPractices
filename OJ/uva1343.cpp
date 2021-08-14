#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

static const int MM{24};
vector<int> vertical1{0, 2, 6, 11, 15, 20, 22};
vector<int> vertical2{1, 3, 8, 12, 17, 21, 23};
vector<int> lateral1{4, 5, 6, 7, 8, 9, 10};
vector<int> lateral2{13, 14, 15, 16, 17, 18, 19};
vector<int> target{6, 7, 8, 11, 12, 15, 16, 17};
vector<int> A{2, 6, 11, 15, 20, 22, 0};
vector<int> B{3, 8, 12, 17, 21, 23, 1};
vector<int> C{10, 4, 5, 6, 7, 8, 9};
vector<int> D{19, 13, 14, 15, 16, 17, 18};
vector<int> E{23, 1, 3, 8, 12, 17, 21};
vector<int> F{22, 0, 2, 6, 11, 15, 20};
vector<int> G{14, 15, 16, 17, 18, 19, 13};
vector<int> H{5, 6, 7, 8, 9, 10, 4};

char ans[1000];
vector<int> inputs(MM, 0);
vector<vector<int>> pp{ A, vertical1, B, vertical2, C, lateral1, D, lateral2, E, vertical2, F, vertical1, G, lateral2, H, lateral1 };
vector<int> tmp(MM, 0);

void
swap_index(vector<int>& raw, vector<int>& to)
{
    int ptr{0};
    for (auto &v: to) {
        tmp[ptr++] = inputs[v];
    }
    ptr = 0;
    for (auto &p: raw) {
        inputs[p] = tmp[ptr++];
    }
}

int
findDiff(int t) 
{
    int diff{0};
    for (int j{0}; j < 8; ++j) {
        if (inputs[target[j]] != t) {
            diff++;
        }
    }
    return diff;
}

bool
foundResult()
{
    for (int i{0}; i < 8; ++i) {
        if (inputs[target[i]] != inputs[target[0]]) {
            return false;
        }
    }
    return true;
}

bool
dfs(int d, int maxd)
{
    if (foundResult()) {
        ans[d] = '\0';
        printf("%s\n", ans);
        return true;
    }
    int mindiff = std::min(findDiff(1), std::min(findDiff(2), findDiff(3)));
    if (d + mindiff > maxd) return false;
    for (int i{0}; i < 16; i += 2) {
        swap_index(pp[i+1], pp[i]);
        ans[d] = ('A'+i/2);
        if (dfs(d+1, maxd)) {
            return true;
        }
        swap_index(pp[i], pp[i+1]);
    }
    return false;
}

int
main(int argc, char** argv)
{
    int d;
    while (true) {
        cin >> d;
        if (!d) break;
        inputs[0] = d;
        for (int i{1}; i < MM; ++i) {
            cin >> inputs[i];
        }
        for (int i{0}; i < MM; ++i) {
            if (!inputs[i]) return 0;
        }
        if (foundResult()) {
            cout << "No moves needed" << endl;
        } else {
            for (int i{1}; ; ++i) {
                if (dfs(0, i)) {
                    break;
                }
            }
        }
        cout << inputs[target[0]] << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

static const int maxn = 1e5 + 1;
vector<int> union_find(maxn, 0);
vector<int> rank_(maxn, 1);

int find_root(int p) 
{
    if (p != union_find[p]) return union_find[p] = find_root(union_find[p]);
    return p;
}
bool is_connected(int p, int q)
{
    return find_root(p) == find_root(q);
}
void connect(int p, int q) 
{
    int p_root = find_root(p), q_root = find_root(q);
    if (p_root == q_root)   return;
    if (rank_[p_root] > rank_[q_root]) {
        union_find[q_root] = p_root;
        rank_[p_root] += rank_[q_root];
    }
    else {
        union_find[p_root] = q_root;
        rank_[q_root] += rank_[p_root];
    }
}

int
main(int argc, char** argv)
{
    int N, P, K, X;
    cin >> N >> K >> P;
    vector<pair<int,int>> frogs(maxn, {0, 0});
    for (int i = 0; i < N; ++i) {
        cin >> X; union_find[i] = i;
        frogs[i] = {X, i+1};
    }
    union_find[N] = N;
    sort(frogs.begin(), frogs.begin()+N);
    for (int i = 1; i < N; ++i) {
        if (frogs[i].first <= frogs[i-1].first+K) {
            connect(frogs[i-1].second, frogs[i].second);
        }
    }
    int p, q;
    while (P--) {
        cin >> p >> q;
        if (is_connected(p, q)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::generate;
using std::begin;
using std::end;

const long MAXSZ{100000+1};
vector<int> id(MAXSZ, 0);
vector<int> sz(MAXSZ, 0);

int
findRoot(int t_p)
{
    auto pRoot{id.at(t_p)};
    if (pRoot != t_p) {
        return id[t_p] = findRoot(pRoot);
    }
    return pRoot;
}

bool 
isConnected(int t_p, int t_q)
{
    return findRoot(t_p) == findRoot(t_q);    
}

void
connect(int t_p, int t_q)
{
    auto pRoot{findRoot(t_p)};
    auto qRoot{findRoot(t_q)};
    if (pRoot != qRoot) {
        if (sz.at(pRoot) > sz.at(qRoot)) {
            sz.at(pRoot) += sz.at(qRoot);
            id.at(qRoot) = id.at(pRoot);
        } else {
            sz.at(qRoot) += sz.at(pRoot);
            id.at(pRoot) = id.at(qRoot);
        }
    }
}

int
main(int argc, char** argv)
{
    generate(begin(id), end(id), [i=0]() mutable {
        return i++;
    });
    int n;
    cin >> n;
    while (n--) {
        int t, a, b, c;
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            connect(a, b);
        } else {
            cin >> a >> b >> c;
            auto isModuloConnected{isConnected(a%c, b%c)};
            if (isModuloConnected) {
                cout << "YES";
            } else {
                cout << "NO";
            }
            cout << endl;
        }
    }
}
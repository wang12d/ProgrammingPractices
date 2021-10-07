#include <bits/stdc++.h>

using std::deque;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::pair;

static const int max{100};
vector<deque<pair<string, int>>> msgq(max, deque<pair<string,int>>{});

int
main()
{
    int n;
    string opt, m;
    cin >> n; int p;
    int t;
    while (n--) {
        cin >> opt;
        if (opt == "out") {
            cin >> p;
            if (p == 0) {
                int maxIndex{-1}; string qfront;
                int t{0}; int ptr{0};
                for (auto &x: msgq) {
                    if (!x.empty()) {
                        if (x.front().second > maxIndex) {
                            qfront = x.front().first;
                            maxIndex = x.front().second;
                            t = ptr;
                        }
                    }
                    ptr++;
                }
                if (qfront.empty()) {
                    cout << -1 << std::endl;
                } else {
                    cout << qfront << std::endl;
                    msgq[t].pop_front();
                }
            } else {
                if (!msgq[p-1].empty()) {
                    cout << msgq[p-1].front().first << std::endl;
                    msgq[p-1].pop_front();
                } else {
                    cout << -1 << std::endl;
                }
            }
        } else {
            cin >> t >> m;
            msgq[t-1].push_back({m, n});
        }
    }
}
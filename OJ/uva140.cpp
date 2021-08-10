#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::string;
using std::for_each;
using std::next_permutation;
using std::transform;
using std::find;
using std::max;
using std::min;

static const string ENDG{"#"};
static const int MAXG{8};
static const int MAXC{26};

int
main(int argc, char** argv)
{
    string graph;
    vector<int> nodeMap(MAXG, 0);
    vector<vector<int>> g(MAXC, vector<int>());
    vector<int> permu(MAXG, 0);
    vector<int> nodes;
    vector<int> ans(MAXG, 0);
    int ansPtr{0};

    int minBandwidth{INT32_MAX};

    while (true) {
        cin >> graph;
        if (graph == ENDG) {
            break;
        } else {
            bool addNode{false};
            char prev;
            nodes.clear();
            for_each(g.begin(), g.end(), [](vector<int>& v) {
                v.clear();
            });

            for_each(graph.begin(), graph.end(), [&](const char& ch) {
                if (ch == ':') {
                    addNode = true;
                } else if (ch == ';') {
                    addNode = false;
                } 
                if (isalpha(ch)) {
                    if (addNode) {
                        g[prev-'A'].push_back(ch-'A');
                        g[ch-'A'].push_back(prev-'A');
                    } else {
                        prev = ch;
                        nodes.push_back(ch-'A');
                    }
                }
            });


            int ptr{0}, cnt{0}; 
            for_each(g.begin(), g.end(), [&](const vector<int>& x) {
                if (!x.empty()) {
                    permu[ptr++] = cnt;
                }
                cnt++;
            });

            minBandwidth = INT32_MAX;
            do {
                int graphBandwidth{-1};
                bool greater = false;
                for (const auto& ch: nodes) {
                    auto firstLoc{find(permu.begin(), permu.begin()+ptr, ch)};
                    int nodeMin{-1};
                    for (const auto& n: g[ch]) {
                        auto secondLoc{find(permu.begin(), permu.begin()+ptr, n)};
                        int distance{abs(static_cast<int>(firstLoc-secondLoc))};
                        nodeMin = max(nodeMin, distance);
                        if (nodeMin >= minBandwidth) {
                            greater = true;
                            break;
                        }
                    }
                    if (greater) {
                        break;
                    }
                    graphBandwidth = max(nodeMin, graphBandwidth);
                }
                if (!greater && graphBandwidth < minBandwidth) {
                    minBandwidth = graphBandwidth;
                    ansPtr = 0;
                    for_each(permu.begin(), permu.begin()+ptr, [&](const int& i) {
                        ans[ansPtr++] = i;
                    });
                }
            } while (next_permutation(permu.begin(), permu.begin()+ptr));
            for_each(ans.begin(), ans.begin()+ansPtr, [&](const int& val) {
                cout << static_cast<char>(val+'A') << ' ';
            });
            cout << '-' << '>' << ' ' << minBandwidth << endl;
        }
    }
}
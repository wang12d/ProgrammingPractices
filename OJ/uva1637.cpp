#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>

using std::map;
using std::stringstream;
using std::cin;
using std::endl;
using std::vector;
using std::pair;
using std::string;

static const int PIELS{9};
using card = vector<char>;
using pi = pair<int,int>;

map<vector<int>, double> dp;

vector<card> cards(PIELS);

double
winningProb(vector<int>& remainc)
{
    if (dp.count(remainc)) {
        return dp.at(remainc);
    }
    int remaincards{0};
    for (auto &x: cards) {
        remaincards += x.size();
    }
    if (remaincards == 0) {
        return 1.0;
    }
    double cnt{0};
    vector<pi> possiblemoves;
    for (int i{0}; i < PIELS; ++i) {
        if (cards[i].empty()) continue;
        for (int j{i+1}; j < PIELS; ++j) {
            if (cards[j].empty()) continue;
            if (cards[i].back() == cards[j].back()) {
                cnt += 1;
                possiblemoves.emplace_back(i, j);
            }
        }
    }
    double res{0.0};
    for (auto &p: possiblemoves) {
        int i{p.first}, j{p.second};
        char iv{cards[i].back()}; char jv{cards[j].back()};
        cards[i].pop_back(); 
        cards[j].pop_back();
        remainc[i]--; remainc[j]--;
        res += winningProb(remainc)/cnt;
        remainc[i]++; remainc[j]++;
        cards[i].emplace_back(iv); 
        cards[j].emplace_back(jv);
    }
    return dp[remainc] = res;
}

int
main()
{
    string line;
    stringstream ss;
    string str;
    while (getline(cin, line)) {
        for (int i{0}; i < PIELS; ++i) {
            cards[i].clear();
        }
        dp.clear();
        ss.clear();
        vector<int> remainc(9, 4);
        ss << line;
        for (int i{0}; i < 4; ++i) {
            ss >> str;
            cards[0].emplace_back(str.front());
        }
        for (int i{1}; i <= 8; ++i) {
            ss.clear();
            getline(cin, line);
            ss << line;
            for (int j{0}; j < 4; ++j) {
                ss >> str;
                cards[i].emplace_back(str.front());
            }
        }
        printf("%.6lf\n", winningProb(remainc));
    }
}
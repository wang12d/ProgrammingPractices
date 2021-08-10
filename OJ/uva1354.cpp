#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::setprecision;

class Tree {
public:
    double left, right;
    double weight;
    Tree():left{0}, right{0}, weight{0} {}
};

void
dfs(vector<Tree>& weights, double& maximumWidth, double r)
{
    if (weights.size() == 1) {
        if (r > weights.front().left+weights.front().right) {
            maximumWidth = max(maximumWidth, weights.front().left+weights.front().right);
        }
    } else {
        auto sz{weights.size()};
        for (auto i{0}; i < sz; ++i) {
            for (auto j{i+1}; j < sz; ++j) {
                // Combine weights[i] and weights[j]
                double leftWeight{weights[i].weight}, rightWeight{weights[j].weight};
                double totalWeight{leftWeight+rightWeight};
                double widthLeft{leftWeight/totalWeight};
                double widthRight{rightWeight/totalWeight};
                Tree t{weights[j]}; Tree u{weights[i]};
                weights[i].left = max(t.left+widthLeft, u.left-widthRight);
                weights[i].right = max(u.right+widthRight, t.right-widthLeft);
                weights[i].weight = totalWeight;
                weights.erase(weights.begin()+j);
                dfs(weights, maximumWidth, r);
                weights[i].left = max(u.left+widthRight, t.left-widthLeft); 
                weights[i].right = max(t.right+widthLeft, u.right-widthRight);
                weights[i].weight = totalWeight;
                dfs(weights, maximumWidth, r);
                weights[i] = u;
                weights.insert(weights.begin()+j, t);
            }
        }
    }
}

int
main(int argc, char** argv)
{
    int m, s;
    double r;
    cin >> m;
    while (m--) {
        cin >> r >> s;
        vector<Tree> weights(s, Tree{});
        for (int i{0}; i < s; ++i) {
            cin >> weights[i].weight;
        }
        double maximumWidth{-1};
        dfs(weights, maximumWidth, r);
        cout << setprecision(10) << maximumWidth << endl;
    }
}
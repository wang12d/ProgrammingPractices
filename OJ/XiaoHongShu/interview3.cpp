#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::endl;
using std::cout;

int
dfs(int a, int b, int loc, int i, vector<int>& sentence)
{
    int d{0};
    if (loc == 1) {
        d += std::max(d, dfs(sentence[i], b, loc+1, i+1, sentence));
    } else if (loc == 2) {
        d += std::max(d, std::max(dfs(a, b, loc, i+1, sentence), dfs(a, b, loc+1, i+1, sentence)));
        if (b > 0) {
            d = std::max(d, dfs(a, b, loc, i+1, sentence));
        }
    }
}

int
main()
{

}
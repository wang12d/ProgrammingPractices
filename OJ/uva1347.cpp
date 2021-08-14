#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

struct Point
{
    int x, y;
    double dist(const Point& rhs) {
        return sqrt(pow(x-rhs.x, 2)+pow(y-rhs.y, 2));
    }
};

int
main(int argc, char** argv)
{
    int n;
    while (cin >> n) {
        vector<Point> points(n);
        vector<vector<double>> dp(n, vector<double>(n, 0.0));
        for (int i{0}; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
        }
        for (int i{n-3}; i >= 0; --i) {
            dp[n-2][i] = points[i].dist(points[n-1]) + points[n-1].dist(points[n-2]);
            dp[i][n-2] = dp[n-2][i];
        }
        for (int i{n-3}; i >= 0; --i) {
            for (int j{i-1}; j >= 0; --j) {
                dp[i][j] = std::min(dp[i+1][j]+points[i].dist(points[i+1]), dp[i+1][i]+points[j].dist(points[i+1]));
                dp[j][i] = dp[i][j];
            }
        }
        printf("%.2lf\n", dp[1][0]+points[1].dist(points[0]));
    }
}
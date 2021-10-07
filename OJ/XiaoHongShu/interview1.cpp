#include <iostream>
#include <vector>
#include <sstream>

using std::stringstream;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int r, c;

vector<int> ORE{0, 1, 2, 3}; // up, right, down, left
static const int totalL{4};
static const string T{"Turn"};
static const string M{"Forward"};
static const string L{"left"};
static const string R{"right"};

int
main()
{
    cin >> r >> c;
    vector<string> maze(r);
    int x,y;
    for (int i{0}; i < r; ++i) {
        cin >> maze[i];
        for (int j{0}; j < c; ++j) {
            if (maze[i][j] == 'R') {
                x = i; y = j;
            }
        }
    }

    int initx{x}, inity{y};
    int command{0};
    cin >> command;
    string line;
    string ops;
    string loc;
    int m;
    auto init{ORE.front()};
    getline(cin, line);
    for (int i{0}; i < command; ++i) {
        getline(cin, line);
        stringstream ss{line};
        ss >> ops;
        if (ops == T) {
            ss >> loc;
            if (loc == R) {
                init = (init+1) % totalL;
            } else {
                init = (init-1+totalL) % totalL;
            }
        } else {
            ss >> m;
            for (int j{0}; j < m; ++j) {
                if (init == ORE[0]) {   // up
                    if (x-1 >= 0 && maze[x-1][y] != 'O') {
                        x--;
                    }
                } else if (init == ORE[1]) {    // right
                    if (y+1 < c && maze[x][y+1] != 'O') {
                        y++;
                    }
                } else if (init == ORE[2]) {    // down
                    if (x+1 < r && maze[x+1][y] != 'O') {
                        x++;
                    }
                } else if (init == ORE[3]) {    // left
                    if (y-1 >= 0 && maze[x][y-1] != 'O') {
                        y--;
                    }
                }
            }
        }
    }
    cout << x-initx << ' ' << y-inity << endl;
}
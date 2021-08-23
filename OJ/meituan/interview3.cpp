#include <iostream>
#include <vector>
#include <stack>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::stack;

int
main()
{
    string s;
    cin >> s;
    static const long long P{1000000007};
    int left{0};
    long long ans{1}; long long tmpVal{0};
    std::stack<long long> st;
    std::stack<long long> sv;
    for (auto &c: s) {
        if (c == ')') {
            st.push(left);
            left = 0;
            st.top()--;
            tmpVal = (tmpVal+1) % P;
            if (st.top() == 0) {
                st.pop();
                sv.push(tmpVal);
                tmpVal = 0;
            }
            if (st.empty()) {
                while (!sv.empty()) {
                    ans = (ans * sv.top()) % P;
                    sv.pop();
                }
            }
        } else {
            sv.push(tmpVal);
            tmpVal = 0;
            left++;
        }
    }
    cout << ans % P << endl;
}
#include <iostream>
#include <unordered_map>

using std::string;
using std::unordered_map;
using std::pair;
using std::cin;
using std::cout;
using std::endl;

int
main()
{
    unordered_map<string, int> memo;
    int n; cin >> n; int c;
    string xx; unordered_map<string,int>::iterator it;
    cin >> xx;    
    for (int i{0}; i < n; ++i) {
        int zerocnt{0}, onecnt{0};
        int ans{1};
        for (auto p = i; p >= 0; --p) {
            char q{xx[p]};
            if (q == '0') {
                zerocnt++;
            } else {
                onecnt++;
            }
            if ((it = memo.find(std::to_string(zerocnt)+'-'+std::to_string(onecnt))) != memo.end()) {
                if (((it->second)+1) * (zerocnt+onecnt) == (i+1)) {
                    it->second++;
                    ans = it->second;
                    memo.insert({std::to_string(it->second*zerocnt)+'-'+std::to_string(it->second*onecnt), 1});
                    break;
                }
            }
        }
        if (ans == 1) {
            memo.insert({std::to_string(zerocnt)+'-'+std::to_string(onecnt), 1});
        }
        if (i) cout << ' ';
        cout << ans;
    }
    cout << endl;
}
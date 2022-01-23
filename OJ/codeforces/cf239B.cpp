#include <bits/stdc++.h>

using namespace std;

int
main(int argc, char** argv)
{
    int n, q;
    string input;
    scanf("%d %d", &n, &q);
    cin >> input;
    int s, t;

    vector<int> outputs(10, 0);
    vector<int> cnt(n, 0);
    vector<bool> valid(n, true);
    for (auto i{0}; i < q; ++i) {
        fill(begin(outputs), end(outputs), 0);
        fill(begin(cnt), end(cnt), 0);
        fill(begin(valid), end(valid), true);
        scanf("%d %d", &s, &t);
        --s; --t;
        int ip{s}; bool mov_right{true};
        while (ip >= s && ip <= t) {
            if (isdigit(input.at(ip))) {
                outputs.at(input.at(ip)-'0'-cnt.at(ip))++;
                cnt.at(ip)++;
                if (cnt.at(ip) > (input.at(ip)-'0')) {
                    valid[ip] = false;
                }
                auto prev_ip{ip};
                int offset{mov_right ? 1 : -1};
                ip += offset;
                while (ip >= s && ip <= t && !valid[ip]){
                    ip += offset;
                }
            } else {
                mov_right = input.at(ip) == '>';
                int offset{mov_right ? 1 : -1};
                int prev_ip{ip};
                ip += offset;
                while (ip >= s && ip <= t && !valid[ip]) {
                    ip += offset;
                }
                if (ip >= s && ip <= t && (input.at(ip) == '>' || input.at(ip) == '<')) {
                    valid.at(prev_ip) = false;
                }
            }
        }
        for_each(begin(outputs), end(outputs), [&outputs, idx=0](const auto& it) mutable {
            if (idx > 0) {
                printf(" ");
            }
            idx++;
            printf("%d", it);
        });
        printf("\n");
    }
}
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::max;
using std::endl;
using std::min;

int
main(int argc, char** argv)
{
    int T;
    cin >> T; int k{0};
    while (T--) {
        long N, S1, V1, S2, V2;
        cin >> N >> S1 >> V1 >> S2 >> V2;
        long a{N/S1}, b{N/S2}, c{max(S1, S2)};
        long minP{min(a, min(b, c))};
        long maxVal{0};
        if (minP == a) {
            for (long i{0}; i <= a; ++i) {
                maxVal = max(maxVal, V1*i+((N-i*S1)/S2)*V2);
            }
        } else if (minP == b) {
            for (long i{0}; i <= b; ++i) {
                maxVal = max(maxVal, V2*i+((N-i*S2)/S1)*V1);
            }
        } else {
            if (S1*V2 < S2*V1) {
                for (long i{0}; i <= S1; ++i) {
                    maxVal = max(maxVal, V2*i+((N-i*S2)/S1)*V1);
                }
            } else {
                for (long i{0}; i <= S2; ++i) {
                    maxVal = max(maxVal, V1*i+((N-i*S1)/S2)*V2);
                }
            }
        }
        cout << "Case #" << ++k << ": " << maxVal << endl;
    }
}
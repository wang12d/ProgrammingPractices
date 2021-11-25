#include <iostream>

using std::cin;
using std::cout;

int
McCarthy(int k, int s, int m, int v)
{
    if (v > m) {
        return v - s;
    }
    return McCarthy(k, s, m, McCarthy(k, s, m, v+k));
}

int
main(int argc, char** argv)
{
    int p;
    int m;
    sscanf(argv[1], "%d", &p);
    sscanf(argv[2], "%d", &m);
    int k, s;
    long ans{0};
    for (long b{1}; b <= p; ++b) {
        bool end{false};
        for (long c{1}; ; ++c) {
            s = b*c;
            if (s > p) {
                end = true;
                break;
            }
            k = b*(c+1);
            if (k <= p) {
                ans += b*m+((b*(b+1))>>1)-b*b*c;
            }
        }
    }
    cout << ans << std::endl;
}
#include <iostream>
#include <vector>
#include "Toolbox.h"

using std::endl;
using std::cout;
using std::vector;

const unsigned long maxn = 1e7+1;
const unsigned long mod = 1e6;
int
main(int argc, char** argv) 
{
    vector<unsigned long> memo(maxn, 0);
    unsigned long odd_prev = 0, even_prev = 2;
    unsigned long odd_save = 0, even_save = 1;
    unsigned long odd_curr = 0, even_curr = 0;
    unsigned long tup;
    for (long i = 6; ; ++i) {
        tup = Toolbox<unsigned long>::powerWithMOD(2, (i-4)/2, mod, 1);
        if (i % 2) {
            tup = (tup + odd_prev + odd_curr) % mod;
            if (tup == 0) {
                cout << i << endl;
                break;
            }
            odd_curr = (odd_curr + odd_save) % mod;
            odd_save = odd_prev;
            odd_prev = tup;
        } else {
            tup = (tup + even_prev + even_curr) % mod;
            if (tup == 0) {
                cout << i << endl;
                break;
            }
            even_curr = (even_curr + even_save) % mod;
            even_save = even_prev;
            even_prev = tup;
        }
    }
}
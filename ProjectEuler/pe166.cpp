#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

int
main(void)
{
    const unsigned min_digit = 0;
    const unsigned max_digit = 9;
    unsigned max_a = max_digit / 2;
    long res = 0;
    for (unsigned a = min_digit; a <= max_a; ++a) 
        for (unsigned b = min_digit; b <= max_digit; ++b) 
            for (unsigned c = min_digit; c <= max_digit; ++c) 
                for (unsigned d = min_digit; d <= max_digit; ++d) 
                {
                    unsigned sum = a + b + c + d;
                    for (unsigned e = b; e <= max_digit; ++e) 
                        for (unsigned f = min_digit; f <= max_digit; ++f) 
                            for (unsigned g = min_digit; g <= max_digit; ++g) 
                            {
                                unsigned h = sum - e - f - g;
                                if (h > max_digit) continue;
                                for (unsigned i = min_digit; i <= max_digit; ++i) 
                                {
                                    unsigned m = sum - a - e - i;
                                    if (m > max_digit) continue;
                                    unsigned j = sum - m - g - d;
                                    if (j > max_digit) continue;
                                    unsigned n = sum - j - b - f;
                                    if (n > max_digit) continue;
                                    for (unsigned k = min_digit; k <= max_digit; ++k) 
                                    {
                                        unsigned o = sum - c - g - k;
                                        if (o > max_digit) continue;
                                        unsigned l = sum - i - j - k;
                                        if (l > max_digit) continue;
                                        unsigned p = sum - n - m - o;
                                        if (p > max_digit || p + a + f + k != sum) continue;
                                        res++;
                                        if (e > b) res++;
                                    }
                                }
                            }
                }

    res *= 2;
    cout << res << endl;
}

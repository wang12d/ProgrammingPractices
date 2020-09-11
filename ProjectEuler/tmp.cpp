#include <iostream>

int main()
{
    // maximum digit
    unsigned int maxDigit = 9;

    // restrict variable "a"
    bool even = (maxDigit + 1) % 2 == 0;
    auto maxA = even ? (maxDigit - 1) / 2 : maxDigit;
    unsigned int result = 0;
    for (unsigned int a = 0; a <= maxA; a++) // limit a to 0..4 => for every solution found there is a "inverted" version where x = 9 - x and x = a,b,c,d,...,p
        for (unsigned int b = 0; b <= maxDigit; b++)
            for (unsigned int c = 0; c <= maxDigit; c++)
                for (unsigned int d = 0; d <= maxDigit; d++)
                {
                    auto sum = a + b + c + d;
                    for (unsigned int e = b; e <= maxDigit; e++) // !!! start at b instead of zero
                        for (unsigned int f = 0; f <= maxDigit; f++)
                            for (unsigned int g = 0; g <= maxDigit; g++)
                            {
                                auto h = sum - e - f - g;
                                if (h > maxDigit) continue;
                                for (unsigned int i = 0; i <= maxDigit; i++)
                                {
                                    auto m = sum - a - e - i;
                                    if (m > maxDigit) continue;
                                    auto j = sum - d - g - m;
                                    if (j > maxDigit) continue;
                                    auto n = sum - b - f - j;
                                    if (n > maxDigit) continue;
                                    for (unsigned int k = 0; k <= maxDigit; k++)
                                    {
                                        auto o = sum - c - g - k;
                                        if (o > maxDigit) continue;
                                        auto l = sum - i - j - k;
                                        if (l > maxDigit) continue;
                                        auto p = sum - m - n - o;
                                        if (p > maxDigit || sum != a + f + k + p) continue; // yes, found a solution
                                        result++;
                                        if (b < e) result++;
                                    }
                                }
                            }
                }

    // add "inverted" solutions
    if (even)
        result *= 2;

    std::cout << result << std::endl;
    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

const int maxn{static_cast<int>(1e5)+1};
const int inf{static_cast<int>(1e9)+1};
std::vector<int> arr(maxn, 0);

int
main(int argc, char** argv)
{
    int n;
    std::cin >> n;
    for (auto i{0}; i < n; ++i) {
        std::cin >> arr.at(i);
    }
    auto start{0}, end{n+1};
    auto start_val{0}, end_val{inf};
    for (auto i{0}; i < n; ++i) {
        if (arr.at(i) > start_val) {
            start++;
            start_val = arr.at(i);
        } else {
            break;
        }
    }
    for (auto i{n-1}; i >= 0; --i) {
        if (arr.at(i) < end_val) {
            end--;
            end_val = arr.at(i);
        } else {
            break;
        }
    }
    if (start > end) {
        std::cout << "yes\n1 1\n";
    } else {
        std::reverse(arr.begin()+start-1, arr.begin()+end);
        if (std::is_sorted(arr.begin(), arr.begin()+n)) {
            std::cout << "yes" << '\n' << start << ' ' << end << '\n';
        } else {
            std::cout << "no" << '\n';
        }
    }
}
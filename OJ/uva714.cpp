#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll maxn{5000000000};
const ll maxm{500};

ll
binarySearch(const ll& k, const vector<ll>& pagesOfBook)
{
    ll lo{*max_element(begin(pagesOfBook), end(pagesOfBook))}, hi{maxn};
    ll ans{0}; const auto sz{pagesOfBook.size()};
    while (hi >= lo) {
        ll mid{lo+((hi-lo)>>1)};
        ll totalPages{0}; int cnt{0};
        bool flag{true};
        for (auto i{static_cast<int>(sz)-1}; i >= 0; --i) {
            totalPages += pagesOfBook.at(i);
            if (totalPages > mid) {
                cnt++;
                totalPages = pagesOfBook.at(i);
                if (i+1 <= k-cnt) {
                    flag = true;
                    break;
                }
            }
            if (i+1 <= k-cnt) {
                flag = true;
                break;
            }
            if (cnt == k) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
            ans = mid;
        }
    }
    return ans;
}

int
main(int argc, char** argv)
{
    ll N;
    ll m, k;
    cin >> N;
    char delimit{'/'};
    for (ll i{0}; i < N; ++i) {
        cin >> m >> k;
        vector<ll> pagesOfBooks(m, 0);
        for (ll j{0}; j < m; ++j) {
            cin >> pagesOfBooks.at(j);
        }
        ll pages{binarySearch(k, pagesOfBooks)};
        ll currentPages{0};
        ll numberOfDelimit{0};
        vector<bool> needDelimit(m, false);
        for (auto j{m-1}; j >= 0; --j) {
            currentPages += pagesOfBooks.at(j);
            if (currentPages > pages) {
                currentPages = pagesOfBooks.at(j);
                numberOfDelimit++;
                needDelimit[j] = true;
                if (k-numberOfDelimit >= j+1) {
                    fill(needDelimit.begin(), needDelimit.begin()+j, true);
                    break;
                }
            }
            if (k-numberOfDelimit >= j+1) {
                fill(needDelimit.begin(), needDelimit.begin()+j, true);
                break;
            }
        }
        for (auto j{0}; j < m; ++j) {
            if (j != 0) {
                cout << ' ';
            }
            cout << pagesOfBooks.at(j);
            if (needDelimit[j]) {
                cout << ' ' << '/';
            }
        }
        std::cout << endl;
    }
}
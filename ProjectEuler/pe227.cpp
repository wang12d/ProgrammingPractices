#include <bits/stdc++.h>
#include "Toolbox.h"


using namespace std;
using ull = unsigned long long;
using ld = long double;
using state = vector<bool>;
using tll = Toolbox<ull>;


static const ld p_left{1.0/6.0};
static const ld p_right{1.0/6.0};
static const ld p_stay{2.0/3.0};
static const ull players{100};
static vector<pair<ld,ld>> prob(players, {.0, .0});
static vector<pair<ld,ld>> pprob(players, {.0, .0});
static const ld EPS{1e-10};


int
main(int argc, char** argv)
{
    tll::timer();
    ull maxTurns{10000};
    if (argc > 1) {
        sscanf(argv[1], "%llu", &maxTurns);
    }

    prob.at(0) = {1.0, .0}; prob.at(50) = {.0, 1.0};
    ld ans{.0};
    for (ull i{0}; i <= maxTurns; ++i) {
        ld end_p{0.0};
        for (ull j{0}; j < players; ++j) {
            end_p += prob.at(j).first*prob.at(j).second;
        }
        // printf("t: %llu p: %.10Lf\n", i, end_p);
        // assert(end_p <= 1.0);
        ans += i*end_p;
        copy(begin(prob), end(prob), begin(pprob));

        for (ull j{0}; j < players; ++j) {
            prob.at(j).first = (1-prob.at(j).second)*(pprob.at(j).first*p_stay+pprob.at((j-1+players)%players).first*p_right+pprob.at((j+1)%players).first*p_left);
            prob.at(j).second = (1-prob.at(j).first)*(pprob.at(j).second*p_stay+pprob.at((j-1+players)%players).second*p_right+pprob.at((j+1)%players).second*p_left);
        }
    }
    cout << setprecision(10) << ans << endl;
    tll::timeCost();
}

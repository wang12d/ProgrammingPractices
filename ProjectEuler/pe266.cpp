#include <bits/stdc++.h>
#include "Toolbox.h"

using namespace std;
using ull = unsigned long long;
using tll = Toolbox<ull>;

ull bound = 190;
const double EPS = 1e-12;
const ull M{static_cast<ull>(1e16)};

int 
main(int argc, char** argv)
{
	tll::timer();
	using pdu = pair<double, ull>;
	if (argc > 1) {
		sscanf(argv[1], "%llu", &bound);
	}

	vector<ull> primes{tll::findPrimes(bound)};
	double square{0.0};
	for_each(begin(primes), end(primes), [&square](const auto& p) {
		square += log(p);
	});
	square *= 0.5;

	ull size{primes.size()};
	ull left_size{size>>1}, right_size{size-(size>>1)};
	vector<pdu> left_half(1ull << left_size);
	vector<pdu> right_half(1ull << right_size);

	auto add_elements = [&primes] (const auto& l_size, const auto& l_offset, vector<pdu>& l_arr) {
		for (auto i{0}; i < (1 << l_size); ++i) {
			double val{0.0};
			for (auto j{0}; j < l_size; ++j) {
				if ((i >> j) & 1) {
					val += log(primes.at(j+l_offset));
				}
			}
			l_arr.at(i) = {val, i};
		}
	};

	auto comp = [](const pdu& a, const pdu& b) {
		return a.first < b.first;
	};

	add_elements(left_size, 0, left_half);
	add_elements(right_size, left_size, right_half);

	sort(begin(left_half), end(left_half), comp);
	sort(begin(right_half), end(right_half), comp);

	ull left_mask{0}, right_mask{0};
	double diff{1e10};
	for (auto& p: left_half) {
		auto lo{lower_bound(begin(right_half), end(right_half), pdu{square-p.first, p.second}, comp)};
		if (lo != begin(right_half)) {
			lo--;
			if (square-p.first-lo->first < diff) {
				left_mask = p.second; right_mask = lo->second;
				diff = square-p.first-lo->first;
			}
		}
	}

	ull ans{1};

	auto calculate_ans = [&primes,  &ans](const auto& l_size, const auto& l_offset, const auto& l_val) {
		for (auto i{0}; i < l_size; ++i) {
			if ((l_val >> i) & 1) {
				ans = ans * primes.at(i+l_offset) % M;
			}
		}
	};

	calculate_ans(left_size, 0, left_mask);
	calculate_ans(right_size, left_size, right_mask);

	cout << ans << endl;
	tll::timeCost();	
}

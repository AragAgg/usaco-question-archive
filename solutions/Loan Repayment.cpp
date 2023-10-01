#include <algorithm>
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;

/**
 * @return whether Farmer John gives Bessie at least N (numGallons)
 * gallons of milk within withinDays with the given X value
 */
bool can_repay(long long num_gallons, long long within_days, long long at_least,
               long long x_val) {
	long long g = 0;
	while (within_days > 0 && g < num_gallons) {
		long long y = (num_gallons - g) / x_val;
		if (y < at_least) {
			long long leftover =
			    ((num_gallons - g) + (at_least - 1)) / at_least;
			return leftover <= within_days;
		}

		long long max_match = num_gallons - (x_val * y);
		long long num_days = std::min((max_match - g) / y + 1, within_days);

		g += y * num_days;  // update values
		within_days -= num_days;
	}

	return g >= num_gallons;
}

int main() {
	std::ifstream read("loan.in");

	long long num_gallons;
	long long within_days;
	long long at_least;
	read >> num_gallons >> within_days >> at_least;

	// binary search on the largest X
	long long low = 1;
	long long high = INT64_MAX / 2;
	while (low < high) {
		long mid = (low + high + 1) / 2;
		if (can_repay(num_gallons, within_days, at_least, mid)) {
			low = mid;
		} else {
			high = mid - 1;
		}
	}

	std::ofstream("loan.out")
	    << low << endl;  // low == high, we can output either
}

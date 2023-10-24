#include <bits/stdc++.h>
using namespace std;

int ask(string s, int a, int b) {
	cout << s << ' ' << a << ' ' << b << endl;
	int res;
	cin >> res;
	return res;
}

/** @return the sum of the elements at a and b (0-indexed) */
int sum(int a, int b) {
	int and_ = ask("and", ++a, ++b);
	int or_ = ask("or", a, b);

	int xor_ = ~and_ & or_;  // a ^ b = ~(a & b) & (a | b)

	return 2 * and_ + xor_;  // a + b = 2(a & b) + a ^ b
}

int main() {
	int n, k;
	cin >> n >> k;

	// Acquire the first 3 elements
	int a_plus_b = sum(0, 1);
	int a_plus_c = sum(0, 2);
	int b_plus_c = sum(1, 2);

	// Get the actual values by solving the equations
	vector<int> arr{(a_plus_b + a_plus_c - b_plus_c) / 2};
	arr.push_back(a_plus_b - arr[0]);
	arr.push_back(a_plus_c - arr[0]);

	// Get the rest of the array
	for (int i = 3; i < n; i++) { arr.push_back(sum(i - 1, i) - arr.back()); }

	sort(arr.begin(), arr.end());
	cout << "finish " << arr[k - 1] << endl;
}

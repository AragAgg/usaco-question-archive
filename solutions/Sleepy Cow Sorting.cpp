#include <bits/stdc++.h>
using namespace std;

int cows[105];

int main() {
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> cows[i]; }
	int answer = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		if (cows[i] < cows[i + 1]) {
			answer = i;
		} else {
			break;
		}
	}
	cout << answer << endl;
}

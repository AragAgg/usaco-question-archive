#include <bits/stdc++.h>
using namespace std;

int dist_sq(pair<int, int> &a, pair<int, int> &b) {
	int dx = a.first - b.first;
	int dy = a.second - b.second;
	return dx * dx + dy * dy;
}

int main() {
	freopen("moocast.in", "r", stdin);

	int N;
	cin >> N;
	vector<pair<int, int>> cows(N);
	for (auto &[x, y] : cows) { cin >> x >> y; }

	/*
	 * shortest distance to a cow in the spanning tree
	 * or INT_MAX - 1 if there are no cows in the spanning tree
	 * or INT_MAX if the cow is in the spanning tree
	 */
	vector<int> dist(N, INT_MAX - 1);
	dist[0] = 0;
	int m = 0;
	for (int t = 0; t < N; t++) {
		int i = min_element(dist.begin(), dist.end()) - dist.begin();
		m = max(m, dist[i]);
		dist[i] = INT_MAX;
		for (int j = 0; j < N; j++) {
			if (dist[j] != INT_MAX) {
				dist[j] = min(dist[j], dist_sq(cows[i], cows[j]));
			}
		}
	}

	freopen("moocast.out", "w", stdout);
	cout << m << endl;
}

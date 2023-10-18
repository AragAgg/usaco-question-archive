/*
Visit through all the points in order. Keep a set to store movies that can be
seen at the moment, using end time to compare. When the current set size is
greater than k, we pick the movie with the largest end time to drop. (because a
larger end time is more likely to overlap with upcoming movies)

Time: O(n log n)
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int ans = n;
  map<int, vector<int>> to_add;
  set<int> points;
  multiset<int> s;
  for (int i = 0; i < n; ++i) {
    int start, end;
    cin >> start >> end;
    points.insert(start);
    points.insert(end);
    to_add[start].push_back(end);
  }
  for (int pt : points) {
    while (!s.empty() && *s.begin() == pt) s.erase(s.begin());
    for (int end : to_add[pt]) {
      s.insert(end);
      if (s.size() > k) {
        ans--;
        s.erase(s.find(*s.rbegin()));
      }
    }
  }
  cout << ans;
}

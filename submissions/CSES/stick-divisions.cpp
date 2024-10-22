#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int m, n;
  cin >> m >> n;
  priority_queue<int, vector<int>, greater<>> pq;
  for (int i = 0, x; i < n; i++) cin >> x, pq.push(x);
  ll res = 0;
  while (pq.size() > 1) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    res += a + b;
    pq.push(a + b);
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}

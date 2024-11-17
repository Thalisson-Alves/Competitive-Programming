#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m, l;
  cin >> n >> m >> l;
  vector<array<int, 3>> sweep;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    sweep.emplace_back() = {a, b, 0};
    mx = max(b-a+1, mx);
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    sweep.emplace_back() = {a, b, 1};
  }
  sort(begin(sweep), end(sweep));
  priority_queue<int> pq;
  int jump = 1, res = 0;
  for (auto [a, b, c] : sweep) {
    if (c) {
      pq.push(b);
      continue;
    }
    while (jump <= b-a+1 and pq.size()) {
      res++;
      jump += pq.top();
      pq.pop();
    }
    if (jump <= b-a+1) {
      cout << "-1\n";
      return;
    }
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  while (t--) solve();
}

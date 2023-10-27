#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0},   {-1, 0}, {0, 1},  {0, -1},
                                  {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void solve() {
  int n, m;
  cin >> n >> m;
  priority_queue<int> pq;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pq.push(x);
  }
  while (not pq.empty() and m--) {
    auto cur = pq.top();
    pq.pop();
    pq.push(cur/2);
  }

  ll sum = 0;
  while (not pq.empty()) {
    sum += pq.top();
    pq.pop();
  }

  cout << sum << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> ps(n, -1), in(n);
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    ps[i] = --x;
    ++in[x];
  }

  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++)
    if (!in[i])
      q.emplace(i, 1);

  vector<int> paths;
  while (!q.empty()) {
    auto [u, d] = q.front();
    q.pop();

    if (!u or --in[ps[u]])
      paths.push_back(d);
    else
      q.emplace(ps[u], d + 1);
  }

  cout << accumulate(paths.rbegin(), paths.rbegin() + k, 0) << '\n';
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

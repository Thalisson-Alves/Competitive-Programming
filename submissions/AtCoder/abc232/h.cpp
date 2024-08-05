#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

vector<pair<int, int>> dfs(int h, int w, int a, int b) {
  vector<pair<int, int>> res;
  if (h == 2) {
    for (int i = 1; i < b; i++) {
      res.emplace_back(1, i);
      res.emplace_back(2, i);
    }
    for (int i = b; i <= w; i++)
      res.emplace_back(3-a, i);
    for (int i = w; i >= b; i--)
      res.emplace_back(a, i);
  } else if (w == 2 or (b == 1 or (b == 2 and a == h))) {
    res = dfs(w, h, b, a);
    for (auto &[x, y] : res) swap(x, y);
  } else {
    for (int i = 1; i <= h; i++)
      res.emplace_back(i, 1);
    auto rest = dfs(w-1, h, b-1, h-a+1);
    for (auto &[x, y] : rest)
      tie(x, y) = make_pair(h+1-y, x+1);
    res.insert(end(res), begin(rest), end(rest));
  }
  return res;
};

void solve() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  for (auto [i, j] : dfs(h, w, a, b))
    cout << i << ' ' << j << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

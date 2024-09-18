#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, s;
  cin >> n >> s;
  --s;
  vector<int> a(n);
  map<int, vector<int>> pos;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    pos[x].push_back(i);
  }
  vector<int> o; o.reserve(size(pos));
  for (auto [x, _] : pos) o.push_back(x);
  vector<vector<tuple<int, int, string_view>>> memo(n, vector<tuple<int, int, string_view>>(size(pos), {-1, -1, ""}));
  auto dp = [&](auto &&self, int i, int j) -> int {
    if (i >= n or j >= (int)size(pos)) return 0;
    auto &[res, best, best_path] = memo[i][j];
    if (~res) return res;
    res = INT_MAX;
    const auto &p = pos[o[j]];
    for (int k = 0; k < (int)size(p); k++) {
      string_view sub;
      int cost = INT_MAX;
      if (p[k] < i) {
        if (!k and p.back() <= i) {
          int c = i-p[k];
          if (cost > c) cost = c, sub = "L";
        } else {
          int nxt = p[(k-1+size(p))%size(p)];
          int c = i-p[k];
          if (nxt > i) c += 2*(nxt-i);
          else c += 2*(n-i+nxt);
          if (cost > c) cost = c, sub = "RL";
        }
        if (k+1 >= (int)p.size() or p[k+1] >= i) {
          int c = n-i+p[k];
          if (cost > c) cost = c, sub = "R";
        } else {
          int c = i-p[k+1]+n-p[k+1]+p[k];
          if (cost > c) cost = c, sub = "LR";
        }
      } else {
        if (i <= p[0] and k == (int)size(p)-1) {
          int c = p[k]-i;
          if (cost > c) cost = c, sub = "R";
        } else {
          int nxt = p[(k+1)%size(p)];
          int c = p[k]-i;
          if (nxt < i) c += 2*(i-nxt);
          else c += 2*(i+n-nxt);
          if (cost > c) cost = c, sub = "LR";
        }
        if (!k or p[k-1] <= i) {
          int c = i+n-p[k];
          if (cost > c) cost = c, sub = "L";
        } else {
          int c = 2*(p[k-1]-i)+i+n-p[k];
          if (cost > c) cost = c, sub = "RL";
        }
      }
      cost += self(self, p[k], j+1);
      if (cost < res) res = cost, best = k, best_path = sub;
    }
    return res;
  };
  cout << dp(dp, s, 0) << '\n';
  if (binary_search(begin(begin(pos)->second), end(begin(pos)->second), s)) cout << "+0\n";
  for (int i = s, j = 0; j < (int)size(pos); j++) {
    const auto &[_, best, best_path] = memo[i][j];
    const auto &p = pos[o[j]];
    const int ci = i;
    for (auto c : best_path) {
      if (c == 'L') {
        for (int cur = (int(lower_bound(begin(p), end(p), ci)-begin(p))-1+size(p))%size(p); cur != best; i = p[cur], cur=(cur+size(p)-1)%size(p))
          cout << "-" + to_string(p[cur] > i ? i+n-p[cur] : i-p[cur]) << '\n';
      } else {
        for (int cur = int(upper_bound(begin(p), end(p), ci)-begin(p))%size(p); cur != best; i = p[cur], cur=(cur+1)%size(p))
          cout << "+" + to_string(p[cur] < i ? n-i+p[cur] : p[cur]-i) << '\n';
      }
    }
    if (p[best] != i) {
      if (best_path.back() == 'L') {
        cout << "-" + to_string(p[best] > i ? i+n-p[best] : i-p[best]) << '\n';
      } else {
        cout << "+" + to_string(p[best] < i ? n-i+p[best] : p[best]-i) << '\n';
      }
    }
    i = p[best];
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}

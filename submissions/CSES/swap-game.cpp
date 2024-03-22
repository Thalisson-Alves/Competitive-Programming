#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  constexpr int n = 3;
  using T = array<array<int, 3>, 3>;
  T mat, target;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
      target[i][j] = n * i + j + 1;
    }
  }

  if (mat == target) {
    cout << "0\n";
    return;
  }

  constexpr auto hash = [](const T &m) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        res = (res << 4) | m[i][j];
      }
    }
    return res;
  };

  ll final = hash(target);
  queue<pair<T, int>> q({{mat, 0}});
  unordered_set<ll> vis({hash(mat)});
  while (not q.empty()) {
    auto [cur, dist] = q.front();
    q.pop();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i + 1 < n) {
          swap(cur[i][j], cur[i + 1][j]);
          auto h = hash(cur);
          if (h == final) {
            cout << dist + 1 << '\n';
            return;
          }
          if (vis.insert(h).second)
            q.emplace(cur, dist + 1);
          swap(cur[i][j], cur[i + 1][j]);
        }
        if (j + 1 < n) {
          swap(cur[i][j], cur[i][j + 1]);
          auto h = hash(cur);
          if (h == final) {
            cout << dist + 1 << '\n';
            return;
          }
          if (vis.insert(h).second)
            q.emplace(cur, dist + 1);
          swap(cur[i][j], cur[i][j + 1]);
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

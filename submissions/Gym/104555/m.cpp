#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

inline void floyd_warshall(vector<vector<ll>> &d) {
  int n = static_cast<int>(d.size());
  for (int i = 0; i < n; i++)
    d[i][i] = 0;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[i][k] < LLONG_MAX and d[k][j] < LLONG_MAX)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<ll>> d(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    for (auto &x : d[i]) cin >> x;
  }

  auto dc = d;
  floyd_warshall(dc);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (d[i][j] > dc[i][j]) {
        cout << "-1\n";
        return;
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (k == i or k == j) continue;
        if (d[i][j] == dc[i][k] + dc[k][j]) {
          ++res;
          d[i][j] = d[j][i] = INT_MAX;
          break;
        }
      }
    }
  }
  cout << res << '\n';
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

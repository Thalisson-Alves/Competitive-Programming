#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  for (auto &x : g) cin >> x;
  vector<vector<int>> pr(n, vector<int>(m+1)), pc(n+1, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      pr[i][j+1] = pr[i][j] + (g[i][j] == '*');
      pc[i+1][j] = pc[i][j] + (g[i][j] == '*');
    }
  }

  vector<string> mat(n, string(m, '.'));
  set<tuple<int, int, int>> res;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) if (g[i][j] == '*') {
      { // right
        int l = j, r = m-1;
        while (l <= r) {
          auto mid = midpoint(l, r);
          if (pr[i][mid+1] - pr[i][j] == mid-j+1) l = mid + 1;
          else r = mid - 1;
        }
        if (r > j and (r+j)%2 == 0) {
          auto d = (r - j) >> 1;
          auto center = j + d;
          if (i-d >= 0 and i+d<n and pc[i+d+1][center] - pc[i-d][center] == 2*d+1)
            res.emplace(i, center, d);
        }
      }
      { // down
        int l = i, r = n-1;
        while (l <= r) {
          auto mid = midpoint(l, r);
          if (pc[mid+1][j] - pc[i][j] == mid-i+1) l = mid + 1;
          else r = mid - 1;
        }
        if (r > i and (r+i)%2 == 0) {
          auto d = (r - i) >> 1;
          auto center = i + d;
          if (j-d>=0 and j+d<m and pr[center][j+d+1] - pr[center][j-d] == 2*d+1)
            res.emplace(center, j, d);
        }
      }
      { // left
        int l = 0, r = j;
        while (l <= r) {
          auto mid = midpoint(l, r);
          if (pr[i][j+1] - pr[i][mid] == j-mid+1) r = mid - 1;
          else l = mid + 1;
        }
        if (j > l and (l+j)%2 == 0) {
          auto d = (j - l) >> 1;
          auto center = j - d;
          if (i-d >= 0 and i+d<n and pc[i+d+1][center] - pc[i-d][center] == 2*d+1)
            res.emplace(i, center, d);
        }
      }
      { // up
        int l = 0, r = i;
        while (l <= r) {
          auto mid = midpoint(l, r);
          if (pc[i+1][j] - pc[mid][j] == i-mid+1) r = mid - 1;
          else l = mid + 1;
        }
        if (i>l and (l+i)%2 == 0) {
          auto d = (i - l) >> 1;
          auto center = i - d;
          if (j-d>=0 and j+d<m and pr[center][j+d+1] - pr[center][j-d] == 2*d+1)
            res.emplace(center, j, d);
        }
      }
    }
  }

  for (auto [i, j, d] : res) {
    for (; ~d; d--)
      mat[i+d][j] = mat[i-d][j] = mat[i][j-d] = mat[i][j+d] = '*';
  }

  if (mat != g) {
    cout << "-1\n";
    return;
  }

  cout << res.size() << '\n';
  for (auto [i, j, d] : res) {
    cout << i+1 << ' ' << j+1 << ' ' << d << '\n';
  }
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

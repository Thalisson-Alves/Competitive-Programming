#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T> struct PrefixSum2d {
  vector<vector<T>> pref;
  PrefixSum2d() {}
  PrefixSum2d(const vector<vector<T>> &mat) { build(mat); }
  void build(const vector<vector<T>> &mat) {
    const int n = (int)mat.size();
    const int m = (int)mat[0].size();
    pref.resize(n+1, vector<T>(m+1));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        pref[i+1][j+1] = pref[i+1][j] + pref[i][j+1] - pref[i][j] + mat[i][j];
  }
  T query(int x1, int y1, int x2, int y2) const {
    return pref[x2+1][y2+1] - pref[x2+1][y1] - pref[x1][y2+1] + pref[x1][y1];
  }
};

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<string> g(n);
  for (auto &x : g) cin >> x;
  PrefixSum2d p1([&](){
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        v[i][j] = g[i][j]-'0';
    return v;
  }());
  PrefixSum2d p2([&](){
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
      for (int j = 1; j < m; j++)
        v[i][j] = g[i][j] == '1' and g[i][j]==g[i][j-1];
    return v;
  }());
  PrefixSum2d p3([&](){
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 1; i < n; i++)
      for (int j = 0; j < m; j++)
        v[i][j] = g[i][j] == '1' and g[i][j]==g[i-1][j];
    return v;
  }());
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a, --b, --c, --d;
    cout << p1.query(a, b, c, d) - p2.query(a, b, c, d) + p2.query(a, b, c, b) - p3.query(a, b, c, d) + p3.query(a, b, a, d) << '\n';
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}

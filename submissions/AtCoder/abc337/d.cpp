#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

template<typename T>
struct BITree2d
{
  int N, M;
  vector<vector<T>> vs;

  BITree2d(int n, int m) : N(n), M(m), vs(n+1, vector<T>(m+1)) {}
  BITree2d(const vector<vector<T>> &v) : BITree2d((int)v.size(), (int)v[0].size()) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        update(i, j, v[i][j]);
      }
    }
  }

  void update(int x, int y, const T& v)
  {
    for (++x; x <= N; x += x & -x)
      for (int i = y + 1; i <= M; i += i & -i)
        vs[x][i] += v;
  }

  T query(int x1, int y1, int x2, int y2)
  {
    return query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1);
  }

  T query(int x, int y)
  {
    if (x < 0 || y < 0) return T();

    T sum = 0;
    for (int i = x+1; i; i -= i & -i)
      for (int j = y+1; j; j -= j & -j)
        sum += vs[i][j];
    return sum;
  }
};

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  BITree2d<ll> ds(n, m), xs(n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
       char c;
       cin >> c;
       if (c == '.') ds.update(i, j, 1);
       else if (c == 'x') xs.update(i, j, 1);
    }
  }

  uint res = UINT_MAX;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j + k <= m and xs.query(i, j, i, j+k-1) == 0)
        res = min(res, (uint)ds.query(i, j, i, j+k-1));
      if (i + k <= n and xs.query(i, j, i+k-1, j) == 0)
        res = min(res, (uint)ds.query(i, j, i+k-1, j));
    }
  }
  cout << (int)res << '\n';
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

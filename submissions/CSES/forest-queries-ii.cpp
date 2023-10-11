#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

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

  // 0-indexed
  void update(int x, int y, const T& v)
  {
    for (++x; x <= N; x += x & -x)
      for (int i = y + 1; i <= N; i += i & -i)
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

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(n));
  for (auto &vi : v) {
    for (auto &x : vi) {
      char c;
      cin >> c;
      x = (c == '*');
    }
  }
  BITree2d<int> bit(v);

  while (m--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      v[x][y] ^= 1;
      bit.update(x, y, (v[x][y] ? 1 : -1));
    } else {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      x1--, y1--, x2--, y2--;
      cout << bit.query(x1, y1, x2, y2) << '\n';
    }
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}

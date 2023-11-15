#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void rotate(vector<vector<int>> &a)
{
  int n = (int)a.size();
  auto ans = a;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      ans[n - 1 - j][i] = a[i][j];
  a = ans;
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
  for (auto &row : a) for (auto &x : row) cin >> x;
  for (auto &row : b) for (auto &x : row) cin >> x;

  for (int i = 0; i < 5; i++)
  {
    auto ans = true;
    for (int k = 0; k < n; k++)
    {
      for (int j = 0; j < n; j++)
        if (a[k][j] == 1 and b[k][j] == 0)
          ans = false;
    }

    if (ans)
    {
      cout << "Yes\n";
      return;
    }

    rotate(a);
    for (auto x: a) {dbg(x);}
    cerr << "___________________\n";
  }
  cout << "No\n";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}


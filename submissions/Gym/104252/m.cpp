#include <bits/stdc++.h>
#include <memory>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

vector<pair<int, int>> dir4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool dfs(const vector<bitset<101>> &g, const vector<bitset<101>> &rots, pair<int, int> pos, int m)
{
  stack<pair<int, int>> st;
  st.emplace(pos);

  set<pair<int, int>> vis;
  vis.emplace(pos);

  while (not st.empty())
  {
    auto [row, col] = st.top(); st.pop();
    if (row == (int)g.size() - 1)
      return true;

    if (not vis.count({row+1, col}) and (g[row+1] & rots[col]).none())
    {
      st.emplace(row+1, col);
      vis.emplace(row+1, col);
    }
    if (row > 0 and not vis.count({row-1, col}) and (g[row-1] & rots[col]).none())
    {
      st.emplace(row-1, col);
      vis.emplace(row-1, col);
    }

    if (not vis.count({row, (col+1) % m}) and (g[row] & rots[(col+1)%m]).none())
    {
      st.emplace(row, (col+1)%m);
      vis.emplace(row, (col+1)%m);
    }
    if (not vis.count({row, (col-1+m)%m}) and (g[row] & rots[(col-1+m)%m]).none())
    {
      st.emplace(row, (col-1+m)%m);
      vis.emplace(row, (col-1+m)%m);
    }
  }
  return false;
}

void fill_rotations(vector<bitset<101>> &rotations, int m)
{
  for (int i = 0; i < m; i++)
  {
    auto last = rotations[i][0];
    rotations[i+1] = rotations[i] >> 1;
    rotations[i+1][m-1] = last;
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<bitset<101>> v(n), rotations(m+1);
  cin >> rotations[0];
  for (auto &x : v) cin >> x;

  fill_rotations(rotations, m);

  bool ans = false;
  for (int i = 0; not ans and i < m; i++)
  {
    if ((v[0]&rotations[i]).none())
      ans |= dfs(v, rotations, {0, i}, m);
  }

  for (int i = 0; i < m / 2; i++)
  {
    bool temp = rotations[0][i];
    rotations[0][i] = rotations[0][m-i-1];
    rotations[0][m-i-1] = temp;
  }

  fill_rotations(rotations, m);
  for (int i = 0; not ans and i < m; i++)
  {
    if ((v[0]&rotations[i]).none())
      ans |= dfs(v, rotations, {0, i}, m);
  }

  cout << (ans ? 'Y' : 'N') << '\n';
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


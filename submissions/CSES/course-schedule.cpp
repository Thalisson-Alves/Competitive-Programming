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

vector<int> topo(const vector<vector<int>> &g, vector<int> &counter)
{
  int n = (int)g.size();
  stack<int> st;
  for (int i = 0; i < n; i++)
    if (counter[i] == 0)
      st.push(i);

  vector<int> ans;
  while (not st.empty())
  {
    auto cur = st.top(); st.pop();
    ans.push_back(cur);
    for (auto x : g[cur])
      if(--counter[x] == 0)
        st.push(x);
  }

  if (ans.size() != counter.size()) return {};

  return ans;
}

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  vector<int> v(n);
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    v[b]++;
  }

  auto path = topo(g, v);
  if (path.empty())
    cout << "IMPOSSIBLE\n";
  else
    for (int i = 0; i < n; i++)
      cout << path[i] + 1 << " \n"[i == n-1];
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


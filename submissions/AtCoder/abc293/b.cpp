#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

void solve()
{
  int n;
  cin >>n;
  vector<int> v(n);
  set<int> st;
  for (auto& x : v) cin >> x, --x;
  for (int i = 0; i < n; i++)
    st.insert(i);
  for (int i = 0; i < n; i++)
  {
    if (st.count(i))
      st.erase(v[i]);
  }
  if (not st.empty())
  {
    cout << st.size() << '\n';
    cout << *st.begin() + 1;

    for (auto it = next(st.begin()); it != st.end(); it++)
      cout << ' ' << *it + 1;
    cout << "\n";
  }
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


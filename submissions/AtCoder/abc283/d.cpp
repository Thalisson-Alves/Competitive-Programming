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
  string s;
  cin >> s;
  set<char> vis;
  stack<set<char>> p;
  p.push({});
  for (auto c : s)
  {
    if (c == '(')
    {
      p.push({});
    }
    else if (c == ')') {
      auto &top =  p.top();
      for (auto x : top)
        vis.erase(x);
      p.pop();
    }
    else {
      p.top().insert(c);
      if (not vis.insert(c).second)
      {
        cout << "No\n";
        return;
      }
    }
  }
  cout << "Yes\n";
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


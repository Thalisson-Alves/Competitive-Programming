#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  string s;
  cin >> s;

  deque<char> ans;
  int open = 0;
  for (auto c : s)
  {
    if (c == '(')
      open += 1;

    if (c == ')' and open == 0)
      ans.push_front('(');

    ans.push_back(c);
    if (open)
      open -= c == ')';
  }

  while (open-- > 0)
    ans.push_back(')');

  string res(all(ans));
  string ok;
  if (all_of(res.begin(), res.begin() + len(res) / 2, [&](char c) { return c == res[0]; }))
    for (int i = 0; i < len(s); i++)
      ok += "()";
  else
  {
    for (int i = 0; i < len(s); i++)
      ok += '(';
    for (int i = 0; i < len(s); i++)
      ok += ')';
  }

  if (ok.find(res) == string::npos)
  {
    cout << "YES\n" << ok << '\n';
  }
  else
  {
    cout << "NO\n";
  }
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}

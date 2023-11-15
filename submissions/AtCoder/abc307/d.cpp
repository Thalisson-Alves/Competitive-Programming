#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;
ll oo = 1e18;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

pair<int, int> expand(int i, int rb, const vector<int> &os, const vector<int> &cs)
{
  auto j = upper_bound(all(cs), os[i]) - cs.begin();
  if (j >= rb)
    return {-1, -1};

  auto lb = j ? cs[j-1] : -1;
  dbg(i, j);

  while (~i and os[i] > lb and j < rb)
  {
    dbg(i, lb, os[i], j, rb);
    i--, j++;
  }
  return {i+1, j-1};
}

void solve()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  string ans;
  stack<int> st;
  for (int i = 0; i < n; i++)
  {
    ans.push_back(s[i]);
    if (s[i] == '(')
      st.push(ans.size() - 1);
    else if (s[i] == ')')
    {
      while (not st.empty() and ans.size() > st.top())
        ans.pop_back();
      if (not st.empty())
        st.pop();
    }
  }

  cout << ans<<'\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}


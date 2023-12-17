#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve()
{
  string s;
  cin >> s;
  vector<int> u, l;
  vector<int> d(s.size());
  for (int i = 0; i < (int)s.size(); i++) {
    auto c = s[i];
    if (c != 'b' and c != 'B') {
      if ('a' <= c)
        l.push_back(i);
      else
        u.push_back(i);
    }

    if (c == 'b' and l.size()) {
      d[l.back()] = 1;
      l.pop_back();
    }
    if (c == 'B' and u.size()) {
      d[u.back()] = 1;
      u.pop_back();
    }
  }
  string res;
  for (int i = 0; i < (int)s.size(); i++) {
    if (not d[i] and s[i] != 'b' and s[i] != 'B') res += s[i];
  }
  cout << res << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

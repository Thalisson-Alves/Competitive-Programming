#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void solve()
{
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  queue<int> q;
  for (int i = 0; i <= n-m; i++) {
    if (s.substr(i, m) == t)
      q.push(i);
  }

  while (not q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int i = 0; i < m; i++) s[i+cur] = '#';
    for (int i = -m-1; i <= m and i+m+cur <= n; i++) {
      if (i+cur < 0) continue;
      bool haschar = 0, ok = 1;
      for (int j = 0; ok and j < m; j++) {
        haschar |= s[i+j+cur] != '#';
        ok &= (s[i+j+cur] == '#' or s[i+j+cur] == t[j]);
      }

      if (ok and haschar)
        q.push(cur+i);
    }
  }

  cout << (all_of(all(s), [](char c) { return c == '#'; }) ? "Yes" : "No") << '\n';
}

int32_t main()
{
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

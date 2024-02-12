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
  int k;
  cin >> s >> k;
  int n = (int)s.size();
  vector<priority_queue<char, vector<char>, greater<>>> v(k);
  for (int i = 0; i < n; i++) {
    v[i % k].push(s[i]);
  }

  s = "";
  for (int i = 0; i < n; i++) {
    s += v[i % k].top();
    v[i % k].pop();
  }
  cout << s << '\n';
}

int32_t main() {
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

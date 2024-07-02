#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  string s;
  cin >> s;
  vector<int> d;
  for (int i = 1; i < (int)s.size(); i++) {
    if (s[i] != s[i-1])
      d.push_back(2 * i + 1);
  }

  vector<ll> p(d.size() + 1);
  p[0] = 1;
  for (auto x : d) {
    for (int i = (int)d.size() - 1; ~i; --i) {
      p[i+1] += p[i];
      p[i] *= -x;
    }
  }

  cout << p.size() - 1 << '\n';
  for (int i = (int)p.size()-1; ~i; --i) {
    cout << ((s[0] == 'A') ^ (p[0] < 0) ? -p[i] : p[i]) << " \n"[!i];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

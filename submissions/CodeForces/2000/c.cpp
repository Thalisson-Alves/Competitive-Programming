#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int m;
  cin >> m;
  while (m--) {
    string s;
    cin >> s;
    if (size(s) != size(a)) {
      cout << "NO\n";
      continue;
    }
    unordered_map<int, char> mp;
    unordered_map<char, int> mb;
    bool res = 1;
    for (int i = 0; i < n; i++) {
      if (mp.count(a[i]) and mp[a[i]] != s[i]) {
        res = 0;
        break;
      }
      if (mb.count(s[i]) and mb[s[i]] != a[i]) {
        res = 0;
        break;
      }
      mp[a[i]] = s[i];
      mb[s[i]] = a[i];
    }
    cout << (res ? "YES" : "NO") << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

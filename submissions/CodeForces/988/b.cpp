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
  vector<string> v(n);
  for (auto &s : v) cin >> s;
  sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
    return a.size() < b.size();
  });

  for (int i = 0; i < n; i++) {
    for (int j = i-1; ~j; --j) {
      if (v[i].find(v[j]) == string::npos) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
  for (auto &x : v) cout << x << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

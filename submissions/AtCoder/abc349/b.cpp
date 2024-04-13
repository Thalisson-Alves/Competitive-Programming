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
  vector<int> hist(27);
  for (auto c : s) hist[c-'a']++;
  sort(hist.begin(), hist.end());
  for (int i = 1; i <= (int)s.size(); i++) {
    auto [a, b] = equal_range(hist.begin(), hist.end(), i);
    if (b - a != 0 and b - a != 2) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
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

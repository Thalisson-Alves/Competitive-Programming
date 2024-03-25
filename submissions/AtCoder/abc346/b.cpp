#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int a, b;
  cin >> a >> b;
  string s = "wbwbwwbwbwbw";
  while (s.size() < 1000) s += s;

  for (int i = 0; i < 13; i++) {
    int ca = 0, cb = 0;
    for (int j = i; ca < a or cb < b; j++) {
      ca += s[j] == 'w';
      cb += s[j] == 'b';
    }
    if (ca == a and cb == b) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
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

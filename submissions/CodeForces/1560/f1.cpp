#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  string n;
  int k;
  cin >> n >> k;
  string res(n.size(), '9');
  for (auto c = '8'; c > '0'; c--) {
    auto nxt = string(n.size(), c);
    if (nxt >= n) res = nxt;
  }
  if (k == 1) {
    cout << res << '\n';
    return;
  }
  if (set<char>(n.begin(), n.end()).size() == 2) {
    cout << n << '\n';
    return;
  }

  for (char a = '0'; a <= '9'; a++) {
    for (char b = a + 1; b <= '9'; b++) {
      for (int i = 0; i < (int)n.size(); i++) {
        if (n[i] < b) {
          auto t = n;
          memset(&t[i + 1], a, n.size() - i - 1);
          if (n[i] < a) t[i] = a;
          else t[i] = b;
          if (t >= n) res = min(res, t);
        }
        if (n[i] != a and n[i] != b)
          break;
      }
    }
  }
  cout << res << '\n';
}

// clang-format off
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

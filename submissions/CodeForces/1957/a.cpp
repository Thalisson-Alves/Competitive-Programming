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
  vector<int> hist(101);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ++hist[x];
  }
  int res = 0;
  for (int i = 0; i <= 100; i++) {
    res += hist[i] / 3;
  }
  cout << res << '\n';
}

int32_t main() {
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

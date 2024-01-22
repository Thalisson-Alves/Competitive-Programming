#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve() {
  int n;
  cin >> n;
  int a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a += x;
    b += y;
  }
  if (a > b)
    cout << "Takahashi\n";
  else if (b > a)
    cout << "Aoki\n";
  else
    cout << "Draw\n";
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

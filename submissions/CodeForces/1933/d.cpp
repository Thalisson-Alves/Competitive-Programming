#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve()
{
  int n;
  cin >> n;
  int g = -1, mn = INT_MAX, cnt = 0;
  for (int i =0 ;i < n; i++) {
    int x;
    cin >> x;
    if (x < mn) {
      mn = x;
      cnt = 1;
    } else if (x == mn) {
      cnt++;
    }
    g = (~g ? gcd(g, x) : x);
  }
  if (cnt == 1 or (g > 0 and g < mn)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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

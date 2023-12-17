#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

void solve() {
  char a, b, c, d;
  cin >> a >> b >> c >> d;
  auto dist = [](char x, char y) {
    if (y < x) swap(x, y);
    return min(y - x, 'E' - y + x - 'A' + 1);
  };

  cout << (dist(a, b) == dist(c, d) ? "Yes" : "No") << '\n';
}

int32_t main()
{
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

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
  int n;
  cin >> n;
  vector<bool> g(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[i] = a == b;
  }
  for (int i = 2; i < n; i++) {
    if (g[i-2] and g[i-1] and g[i]) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
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

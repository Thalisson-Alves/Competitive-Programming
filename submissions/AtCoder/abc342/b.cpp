#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

void solve()
{
  int n;
  cin >> n;
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pos[--x] = i;
  }
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << (pos[a-1] < pos[b-1] ? a : b) << '\n';
  }
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

#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> v(n), pos(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    pos[--v[i]] = i;
  }
  int res = 1;
  for (int i = 1; i < n; i++) {
    res += pos[i] < pos[i-1];
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    int balance = 0;
    if (v[a]) balance -= pos[v[a]] < pos[v[a]-1];
    if (v[a] + 1 < n and v[b] != v[a] + 1) balance -= pos[v[a]+1] < pos[v[a]];
    if (v[b]) balance -= pos[v[b]] < pos[v[b]-1];
    if (v[b] + 1 < n and v[a] != v[b] + 1) balance -= pos[v[b]+1] < pos[v[b]];
    swap(v[a], v[b]);
    swap(pos[v[a]], pos[v[b]]);
    if (v[a]) balance += pos[v[a]] < pos[v[a]-1];
    if (v[a] + 1 < n and v[b] != v[a] + 1) balance += pos[v[a]+1] < pos[v[a]];
    if (v[b]) balance += pos[v[b]] < pos[v[b]-1];
    if (v[b] + 1 < n and v[a] != v[b] + 1) balance += pos[v[b]+1] < pos[v[b]];
    res += balance;
    cout << res << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

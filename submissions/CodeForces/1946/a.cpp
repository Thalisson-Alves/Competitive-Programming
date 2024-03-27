#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  sort(v.begin(), v.end());
  int mid = (n + 1) / 2 - 1;
  cout << upper_bound(v.begin(), v.end(), v[mid]) - v.begin() - mid << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

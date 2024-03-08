#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

void solve()
{
  int n;
  cin >> n;
  vector<int64_t> a(n);
  for (auto &x : a) cin >> x;
  vector<int64_t> ps(n+1);
  partial_sum(a.begin(), a.end(), ps.begin()+1);
  int q;
  cin >> q;

  constexpr auto cost = [](int64_t x) -> int64_t { return x * (x - 1) / 2; };
  while (q--) {
    int64_t L, u;
    cin >> L >> u;
    --L;
    auto value = [&](int64_t m) { return u * (ps[m+1]-ps[L]) - cost(ps[m+1]-ps[L]); };
    int l = (int)L, r = n-1;
    while (l <= r) {
      auto m1 = l + (r - l) / 3;
      auto m2 = r - (r - l) / 3;
      auto v1 = value(m1);
      auto v2 = value(m2);
      if (v1 >= v2) r = m2-1;
      else if (v1 < v2) l = m1+1;
    }
    cout << l + 1 << ' ';
  }
  cout << '\n';
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

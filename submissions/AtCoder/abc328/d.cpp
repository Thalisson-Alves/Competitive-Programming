#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

void solve()
{
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> pref(n+1);
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i-1] + (s[i] == s[i-1]);
  }
  dbg(pref);
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << pref[r-1] - pref[l-1] << '\n';
  }
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

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
  int n, t;
  cin >> n >> t;
  vector<ll> s(n);
  map<ll, int> mp;
  mp[0] = n;
  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    if (--mp[s[a]] == 0) {
      mp.erase(s[a]);
    }
    s[a] += b;
    mp[s[a]]++;
    cout << mp.size() << '\n';
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

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
  string s;
  cin >> s;
  vector<int> hist(30);
  for (auto c : s) hist[c-'a']++;
  sort(all(hist), greater<>());

  int diff = hist[0];
  for (int i = 1; hist[i]; i++)
    diff -= hist[i];

  cout << max(diff, n&1) << '\n';
}

int32_t main()
{
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

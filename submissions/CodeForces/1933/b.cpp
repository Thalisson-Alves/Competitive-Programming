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
  vector<int> hist(3);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    hist[x%3]++;
    sum = (sum + x) % 3;
  }
  if (sum == 0) cout << "0\n";
  else if (hist[sum] or sum == 2) cout << "1\n";
  else cout << "2\n";
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

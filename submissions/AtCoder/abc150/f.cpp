#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

template <typename T> vector<int> z_function(const T &s) {
  vector<int> z(s.size());
  int l = 0, r = 0;
  for(int i = 1; i < (int)s.size(); i++) {
    if(i < r) {
      z[i] = min(r - i, z[i - l]);
    }
    while(i + z[i] < (int)s.size() && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if(i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  vector<int> c(3*n);
  for (int i = 0; i < n; i++)
    c[i] = b[i]^b[(i+1)%n];
  for (int i = n; i < (int)c.size(); i++)
    c[i] = a[i%n]^a[(i+1)%n];

  auto z = z_function(c);

  for (int i = 0; i < n; i++) {
    if (z[i+n] >= n-1) {
      cout<< i << ' ' << (a[i]^b[0]) << '\n';
    }
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

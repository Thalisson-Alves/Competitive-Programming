#include <bits/stdc++.h>
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
  string s;
  cin >> s;

  auto z = z_function(s);
  for (int i = (int)s.size()-1; ~i; --i) {
    if (z[i] == (int)s.size() - i)
      cout << s.size() - i << ' ';
  }
  cout << '\n';
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

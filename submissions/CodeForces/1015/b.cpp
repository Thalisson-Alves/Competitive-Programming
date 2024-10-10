#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  {
    auto sc = s;
    auto st = t;
    sort(sc.begin(), sc.end());
    sort(st.begin(), st.end());
    if (sc != st) {
      cout << "-1\n";
      return;
    }
  }

  vector<int> res;
  for (int i = n-1; ~i; --i) {
    int pos = -1;
    for (int j = i; pos == -1 and ~j; --j) {
      if (s[j] == t[i])
        pos = j;
    }
    for (; pos < i; pos++) {
      res.push_back(pos);
      swap(s[pos], s[pos+1]);
    }
  }
  assert(s == t);
  cout << res.size() << '\n';
  for (auto x : res) cout << x + 1 << ' ';
  cout << '\n';
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

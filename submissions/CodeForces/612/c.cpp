#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  string s;
  cin >> s;
  stack<char> st;
  int res = 0;
  for (auto c : s) {
    auto id = string_view(">}])").find(c);
    if (id != string::npos) {
      if (empty(st)) { st.push(c); break; }
      res += "<{[("[id] != st.top();
      st.pop();
    } else {
      st.push(c);
    }
  }
  if (size(st)) cout << "Impossible\n";
  else cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}

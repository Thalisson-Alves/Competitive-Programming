#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  constexpr auto comp = [](char a, char b) -> bool {
    static set<pair<char, char>> st({{'B','S'},{'C','F'}});
    return st.count(minmax(a, b));
  };
  for (string s; cin >> s;) {
    vector<char> st;
    int res = 0;
    for (auto c : s) {
      st.push_back(c);
      while (st.size() > 1 and comp(st[st.size()-2], st.back())) {
        st.pop_back();
        st.pop_back();
        res += 1;
      }
    }
    cout << res << '\n';
  }
}

// clang-format off
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

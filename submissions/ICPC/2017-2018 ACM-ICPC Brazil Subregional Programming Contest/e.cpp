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
  cin >> n;

  const vector<string> notes = {
      "do",  "do#", "re",   "re#", "mi",  "fa",
      "fa#", "sol", "sol#", "la",  "la#", "si",
  };
  constexpr array<int, 7> offset = {2, 2, 1, 2, 2, 2, 1};

  set<int> st;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.insert((x - 1) % (int)notes.size());
  }

  for (int i = 0; i < (int)notes.size(); i++) {
    int pref = i;
    set<int> scale({pref});
    for (int j = 0; j < (int)offset.size(); j++)
      scale.insert((pref += offset[j]) % (int)notes.size());
    bool found = 1;
    for (auto x : st) {
      if (!scale.count(x)) {
        found = 0;
        break;
      }
    }
    if (found) {
      cout << notes[i] << '\n';
      return;
    }
  }
  cout << "desafinado\n";
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

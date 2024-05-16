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
  unordered_multiset<string> all;
  vector<string> v;
  string a, b;
  for (string s; cin >> s;) {
    if ((int)s.size() == n-1) {
      if (a.empty()) a = s;
      else b = s;
    }
    v.emplace_back(s);
    all.insert(s);
  }

  auto is_string = [&](const string &s) {
    int m = (int)s.size();
    auto st = all;
    string pref, suf;
    for (int i = 0; i < m-1; i++) {
      pref += s[i];
      suf += s[m-i-1];
      if (st.extract(pref).empty()) return false;
      if (st.extract(string(suf.rbegin(), suf.rend())).empty()) return false;
    }
    return true;
  };
  string s = a[0] + b;
  if (!is_string(s)) s = b[0] + a;
  assert(is_string(s));

  unordered_set<string> prefs;
  string pref = "";
  for (auto c : s) {
    pref += c;
    prefs.insert(pref);
  }

  for (auto x : v) {
    auto it = prefs.find(x);
    cout << "SP"[it != prefs.end()];
    if (it != prefs.end()) prefs.erase(it);
  }
  cout << '\n';
}

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

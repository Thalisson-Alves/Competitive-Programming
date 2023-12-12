#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

string de_bruijn(const string &alphabet, int n) {
  string res;
  stack<int> st({0});
  unordered_set<string> vis;

  ll MAX = 1;
  for (int i = 0; i < n; i++)
    MAX *= alphabet.size();

  while (not st.empty()) {
    if ((int)vis.size() == MAX) return res;

    auto &cur = st.top();
    if (cur >= (int)alphabet.size()) {
      st.pop();
      if ((int)res.size() >= n)
        vis.erase(res.substr(res.size() - n));
      res.pop_back();
      continue;
    }

    res += alphabet[cur++];
    if ((int)res.size() < n or vis.emplace(res.substr(res.size() - n)).second) {
      st.push(0);
    } else {
      res.pop_back();
    }
  }

  return "";
}

void solve() {
  int n;
  cin >> n;

  cout << de_bruijn("01", n) << '\n';
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

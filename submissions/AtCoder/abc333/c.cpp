#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;
  vector<string> st;
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++) {
      for (int k = 1; k < 12; k++) {
        auto s = string(i, '1') + string(j, '2') + string(k, '3');
        if (s.size() < 15)
          st.emplace_back(s);
      }
    }
  }

  sort(all(st), [](const auto &a, const auto &b) { return stoll(a) < stoll(b); });
  cout << st[n-1] << '\n';
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

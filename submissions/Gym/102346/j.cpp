#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  --k;

  constexpr string_view order = "A23456789DQJK";
  vector<string> hands(n);
  for (auto &x : hands) cin >> x;
  constexpr auto win = [](const string &s) {
    return s.size() == 4 and set<char>(s.begin(), s.end()).size() == 1;
  };
  char last = 'C';
  hands[k].push_back(last);
  for (;;) {
    for (int i = 0; i < n; i++) {
      if (win(hands[i])) {
        cout << i + 1 << '\n';
        return;
      }
    }

    if (last != 'C' and hands[k].find('C') != string::npos) last = 'C';
    else {
      int best_cnt = 10;
      for (auto c : hands[k]) {
        if (c == 'C') continue;
        int cnt = (int)count(hands[k].begin(), hands[k].end(), c);
        if (best_cnt > cnt or (best_cnt == cnt and order.find(last) > order.find(c))) {
          best_cnt = cnt;
          last = c;
        }
      }
    }

    hands[k].erase(hands[k].find(last), 1);
    (k += 1) %= n;
    hands[k].push_back(last);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

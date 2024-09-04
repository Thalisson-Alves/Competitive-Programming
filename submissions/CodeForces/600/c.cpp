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
  vector<int> hist(26);
  for (auto c : s) hist[c-'a']++;
  deque<int> odds;
  for (int i = 0; i < 26; i++) if (hist[i]&1) odds.push_back(i);
  while (size(odds) > 1) {
    hist[odds.back()]--;
    odds.pop_back();
    hist[odds.front()]++;
    odds.pop_front();
  }
  deque<char> res;
  if (size(odds)) {
    res.push_back(odds.back()+'a');
    hist[odds.back()]--;
  }
  for (int i = 25; ~i; --i)
    while (hist[i])
      res.push_front(i+'a'), res.push_back(i+'a'), hist[i]-=2;
  for (auto x : res) cout << x;
  cout << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}

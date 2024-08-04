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
  int n = (int)s.size();
  vector<ll> pref(s.size() + 1);
  for (int i = 0; i < (int)s.size(); i++) {
    pref[i+1] = pref[i] + s[i]-'0';
  }
  ll carry = 0;
  string res;
  for (int i = 0; i < (int)s.size(); i++) {
    carry += pref[n-i];
    res.push_back('0'+carry%10);
    carry /= 10;
  }
  if (carry) {
    auto cs = to_string(carry);
    reverse(cs.begin(), cs.end());
    res += cs;
  }
  reverse(res.begin(), res.end());
  cout << res << '\n';
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

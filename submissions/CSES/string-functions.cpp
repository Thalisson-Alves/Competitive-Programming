#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

template <typename T> vector<int> z_function(const T &s) {
  vector<int> z(s.size());
  int l = 0, r = 0;
  for(int i = 1; i < (int)s.size(); i++) {
    if (i < r) z[i] = min(r - i, z[i - l]);
    for (; i + z[i] < (int)s.size() && s[z[i]] == s[i + z[i]]; z[i]++);
    if (i + z[i] > r) l = i, r = i + z[i];
  }
  return z;
}

vector<int> kmp(const string &s) {
  vector<int> pi(size(s));
  for (int i = 1; i < (int)size(s); i++) {
    int j = pi[i-1];
    for (; j and s[i]!=s[j]; j=pi[j-1]);
    pi[i] = j+(s[i]==s[j]);
  }
  return pi;
}

void solve() {
  string s;
  cin >> s;
  auto z = z_function(s);
  auto pi = kmp(s);
  for (int i = 0; i < (int)size(s); i++)
    cout << z[i] << " \n"[i == (int)size(s)-1];
  for (int i = 0; i < (int)size(s); i++)
    cout << pi[i] << " \n"[i == (int)size(s)-1];
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}

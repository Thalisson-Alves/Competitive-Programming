#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  string s; cin >> s;
  int n = (int)s.size();
  s += s;
  ll k; cin >> k;
  vector<int> es;
  for (int i = 0; i < (int)s.size(); i++)
    if (s[i] == 'E')
      es.push_back(i);
  if (es.empty()) {
    cout << "0\n";
    return;
  }

  ll res = 0;
  for (int i = 0; i < n; i++) {
    ll dist = *lower_bound(es.begin(), es.end(), i) - i;
    res += max(k - dist, 0ll);
  }
  cout << res << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  static vector<bool> is_prime(1e6, 1);
  if (is_prime[4]) {
    for (int i = 2; i < (int)is_prime.size(); i++) if (is_prime[i]) {
      for (int j = i+i; j < (int)is_prime.size(); j+=i)
        is_prime[j] = 0;
    }
  }
  vector<int> res;
  for (int i = 1; i <= n; i+=2) res.push_back(i);
  int m = (int)res.size()-1;
  for (int i = 2; i <= n; i+=2) res.push_back(i);
  for (int i = m+1; i < n; i++) {
    if (!is_prime[res[m]+res[i]]) {
      swap(res[m+1], res[i]);
      break;
    }
  }
  if (is_prime[res[m]+res[m+1]]) cout << "-1\n";
  else {
    for (int i = 0; i < n; i++) cout << res[i] << " \n"[i == n-1];
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  while (t--) solve();
}

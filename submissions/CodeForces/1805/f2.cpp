#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  sort(begin(a), end(a));
  constexpr int MAX = 64;
  a.resize(min(n, MAX));
  constexpr ll mod = 1e9+7;
  ll res = 0;
  for (; n > 1; n--) {
    ll k = a[0];
    for (auto &x : a) x -= k;
    (res += res + 2 * k % mod) %= mod;
    using T = tuple<ll, ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    for (int i = 0; i < (int)a.size()-1; i++)
      pq.emplace(a[i]+a[i+1], i, i+1);
    vector<ll> b(min(n-1, MAX));
    for (auto &x : b) {
      auto [sum, i, j] = pq.top();
      x = sum;
      pq.pop();
      if (++j < (int)a.size()) pq.emplace(a[i]+a[j], i, j);
    }
    swap(a, b);
  };
  cout << (a[0] + res) % mod << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}

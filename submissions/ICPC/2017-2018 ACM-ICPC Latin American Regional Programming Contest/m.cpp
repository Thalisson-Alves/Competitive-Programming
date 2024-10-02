#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

template <int alphabet = 128>
vector<int> sort_cyclic_shifts(const auto &s) {
  int n = (int)size(s);
  vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
  for (int i = 0; i < n; i++) cnt[s[i]]++;
  for (int i = 1; i < alphabet; i++) cnt[i] += cnt[i - 1];
  for (int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
  c[p[0]] = 0;
  int classes = 1;
  for (int i = 1; i < n; i++) {
    if (s[p[i]] != s[p[i-1]]) classes++;
    c[p[i]] = classes - 1;
  }
  vector<int> pn(n), cn(n);
  for (int h = 0; (1 << h) < n; ++h) {
    for (int i = 0; i < n; i++) {
      pn[i] = p[i] - (1 << h);
      if (pn[i] < 0) pn[i] += n;
    }
    fill(cnt.begin(), cnt.begin() + classes, 0);
    for (int i = 0; i < n; i++) cnt[c[pn[i]]]++;
    for (int i = 1; i < classes; i++) cnt[i] += cnt[i-1];
    for (int i = n-1; ~i; --i) p[--cnt[c[pn[i]]]] = pn[i];
    cn[p[0]] = 0;
    classes = 1;
    for (int i = 1; i < n; i++) {
      pair<int, int> cur = {c[p[i]], c[(p[i]+(1<<h))%n]};
      pair<int, int> prev = {c[p[i-1]], c[(p[i-1]+(1<<h))%n]};
      if (cur != prev) ++classes;
      cn[p[i]] = classes-1;
    }
    c.swap(cn);
  }
  return p;
}
template <int sz = 256>
vector<int> suffix_array(auto s) {
  s.push_back(0);
  auto res = sort_cyclic_shifts<sz>(s);
  res.erase(begin(res));
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<int> s, ks(n);
  for (int i = 0; i < n; i++) {
    cin >> ks[i];
    for (int j = 0, x; j < ks[i] and cin >> x; j++) s.push_back(x);
    s.emplace_back(301);
  }
  partial_sum(begin(ks), end(ks), begin(ks));
  ks.insert(begin(ks), 0);
  vector<int> w(size(s));
  for (int i = 0; auto o : sort_cyclic_shifts<302>(s)) w[o] = i++;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  for (int i = 0; i < n; i++) pq.emplace(w[ks[i]+i], ks[i]+i);
  constexpr ll mod = 1e9+7;
  vector<ll> pws(ks.back()+1);
  pws[0] = 1;
  for (int i = 1; i < (int)size(pws); i++) pws[i] = pws[i-1] * 365 % mod;
  ll res = 0;
  for (int d = (int)size(pws)-1; size(pq); --d) {
    auto [_, pos] = pq.top();
    pq.pop();
    (res += s[pos] * pws[d] % mod) %= mod;
    if (s[pos+1] < 301)
      pq.emplace(w[pos+1], pos+1);
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}

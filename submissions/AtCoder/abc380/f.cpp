#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<int p1=(int)2e5+3, int p2=(int)2e5+9, int q1=(int)1e9+7, int q2=(int)1e9+9> struct HashHistogram {
  using H = pair<int, int>;
  static H mul(H a, H b) { return {(ll)a.first*b.first%q1, (ll)a.second*b.second%q2}; }
  static H mul(H a, ll x) { return {(ll)a.first*(x%q1)%q1, (ll)a.second*(x%q2)%q2}; }
  static H add(H a, H b) { return {(a.first+b.first)%q1, (a.second+b.second)%q2}; }
  static H sub(H a, H b) { return {(a.first-b.first+q1)%q1, (a.second-b.second+q2)%q2}; }
  static inline vector<H> pows{{1, 1}, {p1, p2}};
  static inline H power(int i) {
    while ((int)pows.size() <= i) pows.push_back(mul(pows.back(), pows[1]));
    return pows[i];
  }
  vector<H> pref;
  HashHistogram() : pref(1) {}
  HashHistogram(const auto &hist) : HashHistogram() { add(hist); }
  void add(int idx, int x) {
    pref.push_back(add(pref.back(), mul(power(idx), x)));
  }
  template <typename T> void add(const vector<T> &hist) {
    pows.reserve(pows.size() + hist.size());
    auto &res = pref.emplace_back();
    for (int i = 0; i < (int)hist.size(); i++)
      res = add(res, mul(power(i), hist[i]));
  }
  H hash() const { return pref.back(); }
  int size() const { return (int)pref.size() - 1; }
  bool operator<(const HashHistogram &a) const { return hash() < a.hash(); }
  H hash(int l) const { return hash(l, size()-1); }
  H hash(int l, int r) {
    assert(0 <= l and l <= r and r < size());
    return sub(pref[r+1], pref[l]);
  }
};

void solve() {
  int n, m, l;
  cin >> n >> m >> l;
  vector<int> a(n), b(m), c(l);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  for (auto &x : c) cin >> x;
  vector<int> all(begin(a), end(a));
  all.insert(all.end(), begin(b), end(b));
  all.insert(all.end(), begin(c), end(c));
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  map<pair<pair<int, int>, pair<int, int>>, bool> dp;
  constexpr auto play = [](auto &ha, auto &hb, int i) { ha[i]--; hb[i]++; };
  auto dfs = [&](auto &&self, vector<int> &ha, vector<int> &hb, vector<int> &hc) -> bool {
    auto key = make_pair(HashHistogram(ha).hash(), HashHistogram(hc).hash());
    auto it = dp.find(key);
    if (it != dp.end()) return it->second;
    auto &res = dp[key];
    for (int i = 0; !res and i < (int)ha.size(); i++) if (ha[i]) {
      play(ha, hc, i);
      res |= !self(self, hb, ha, hc);
      for (int j = 0; !res and j < i; j++) if (hc[j]) {
        play(hc, ha, j);
        res |= !self(self, hb, ha, hc);
        play(ha, hc, j);
      }
      play(hc, ha, i);
    }
    return res;
  };
  vector<int> ha(all.size()), hb(all.size()), hc(all.size());
  for (auto x : a) ha[lower_bound(all.begin(), all.end(), x)-all.begin()]++;
  for (auto x : b) hb[lower_bound(all.begin(), all.end(), x)-all.begin()]++;
  for (auto x : c) hc[lower_bound(all.begin(), all.end(), x)-all.begin()]++;
  cout << (!dfs(dfs, ha, hb, hc) ? "Aoki" : "Takahashi") << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

template<typename T, typename D=bool>
struct BlockSet {
  map<T, pair<T, D>> blocks;
  function<void(T,T,D)> fset, frem;
  function<void(T,T,T,D)> fupd;
  template <typename F, typename U, typename R>
  BlockSet(F s, U u, R r) : fset(s), frem(r), fupd(u) {}
  void merge(T l, T r) {
    auto it = blocks.upper_bound(l);
    if (it == end(blocks)) return;
    if (it == begin(blocks)) ++it;
    while (it != end(blocks) and it->first <= r) {
      auto il = prev(it);
      auto ir = it++;
      if (il->second.first >= l) merge(il, ir);
    }
  }
  void remove(T l, T r) {
    auto it = blocks.upper_bound(l);
    if (it != begin(blocks)) --it;
    if (it == end(blocks) or it->first > r) return;
    if (it->first < l and r < it->second.first) {
      split(it, l, r);
      return;
    }
    if (it->first < l) shrink_right(it++, l-1);
    while (it != end(blocks) and it->second.first <= r) remove(it++);
    if (it != end(blocks) and it->first <= r) shrink_left(it, r+1);
  }
  void add(T l, T r) {
    add_unchecked(l, r);
    merge(l, r);
  }
  void add_unchecked(T l, T r, D d=D()) {
    auto it = blocks.find(l);
    if (it != end(blocks)) remove(it);
    insert(l, r, d);
  }
private:
  void insert(T l, T r, D d) {
    assert(!blocks.count(l));
    fset(l, r, d);
    blocks[l] = {r, d};
  }
  void shrink_left(auto it, int l) {
    insert(l, it->second.first, it->second.second);
    remove(it);
  }
  void shrink_right(auto it, int r) {
    auto [l, rp] = *it;
    fupd(l, r, rp.first, rp.second);
    it->second.first = r;
  }
  void remove(auto it) {
    frem(it->first, it->second.first, it->second.second);
    blocks.erase(it);
  }
  void split(auto it, T il, T ir) {
    auto [r, d] = it->second;
    shrink_right(it, il-1);
    insert(ir+1, r, d);
  }
  void merge(auto il, auto ir) {
    shrink_right(il, ir->second.first);
    remove(ir);
  }
};

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> hist(m);
  auto fset = [&](int l, int r, int v) { hist[v] += r-l+1; };
  auto fupd = [&](int l, int r, int pr, int v) { hist[v] += (r-l+1)-(pr-l+1); };
  auto frem = [&](int l, int r, int v) { hist[v] -= r-l+1; };
  BlockSet<int, int> bs(fset, fupd, frem);
  bs.add_unchecked(0, n-1, 0);
  while (q--) {
    int p, x, a, b;
    cin >> p >> x >> a >> b;
    --p, --x;
    ll s = hist[p];
    int m1 = int((a+s*s)%n);
    int m2 = int((a+(s+b)*(s+b))%n);
    if (m1 > m2) swap(m1, m2);
    bs.remove(m1, m2);
    bs.add_unchecked(m1, m2, x);
  }
  cout << *max_element(begin(hist), end(hist)) << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}

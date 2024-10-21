#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UFDS {
  vector<int> ps, sz;
  int components;
  UFDS(int n = 0) : ps(n), sz(n, 1), components(n) {
    iota(ps.begin(), ps.end(), 0);
  }
  int find(int x) { return (x == ps[x] ? x : (ps[x] = find(ps[x]))); }
  bool same(int x, int y) { return find(x) == find(y); }
  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    ps[y] = x;
    sz[x] += sz[y];
    --components;
    return true;
  }
  int add() {
    int id = (int)ps.size();
    ps.push_back(id);
    sz.push_back(1);
    ++components;
    return id;
  };
};

/* Tree Minimum Inversion Permutation
 *
 * Given a tree in the form of a parent sequence ps,
 * returns a permutation q such that order[ps[i]] < order[i] for all i
 * and minimizes \sum_{i=0,1,...,n-1}(v[q[i]].first * \sum_{j=0,1,...,i}v[q[j]].second)
 *
 * The tree is represented by a parent sequence ps, where ps[i] = -1 if i is the root
 *
 * Complexity: O(n log n)
 */
vector<int> min_inversion_permutation(const vector<int> &ps, const vector<pair<int, int>> &v) {
  using T = tuple<ll, ll, int>;
  constexpr auto comp = [](const T &a, const T &b) {
    return get<0>(a)*get<1>(b) < get<0>(b)*get<1>(a);
  };
  priority_queue<T, vector<T>, decltype(comp)> pq(comp);
  int root = -1;
  vector<int> f(size(ps), -1), first(size(ps)), last(size(ps));
  vector<pair<ll, ll>> val(size(ps));
  for (int i = 0; i < (int)size(ps); i++) {
    if (~ps[i]) pq.emplace(v[i].first, v[i].second, i);
    else root = i;
    first[i] = last[i] = i;
    val[i] = v[i];
  }
  UFDS ufds((int)size(ps));
  while (size(pq)) {
    auto [zeros, ones, i] = pq.top();
    pq.pop();
    int p = ufds.find(ps[i]);
    i = ufds.find(i);
    if (!ufds.join(i, p)) continue;
    int x = ufds.find(i);
    f[last[p]] = first[i];
    first[x] = first[p];
    last[x] = last[i];
    val[x] = {val[i].first + val[p].first, val[i].second + val[p].second};
    if (~ps[first[x]]) pq.emplace(val[x].first, val[x].second, first[x]);
  }
  vector<int> res;
  for (; ~root; root = f[root]) res.push_back(root);
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<int> p(n-1);
  for (auto &x : p) cin >> x, --x;
  p.insert(begin(p), -1);
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    (x ? a[i].second : a[i].first)++;
  }
  auto perm = min_inversion_permutation(p, a);
  ll res = 0;
  for (int ones = 0; auto i : perm) {
    if (a[i].first) res += ones;
    else ++ones;
  }
  cout << res << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (int i = 1; i <= t; i++) {
    solve();
  }
}

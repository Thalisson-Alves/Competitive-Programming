/* Calculate the area of the union of rectangles
 * Complexity: O(N log N)
 * Parameters:
 * - rect: vector of rectangles represented by {l, d, r, u}
*/
template<typename T> ll area_union_rectangles(const vector<array<T, 4>> &rect) {
  struct Node {
    ll len, cnt;
    T mn;
  };
  auto op = [](Node a, Node b) -> Node {
    if (a.mn<b.mn) return a.len+=b.len,a;
    if (b.mn<a.mn) return b.len+=a.len,b;
    return {a.len+b.len,a.cnt+b.cnt,a.mn};
  };
  using Lazy = int;
  auto mapping = [](Lazy f, Node x, [[maybe_unused]] pair<int, int> lr) -> Node {
    return x.mn += f, x;
  };
  auto composition = [](Lazy f, Lazy g, [[maybe_unused]] pair<int, int> lr) -> Lazy {
    return f + g;
  };
  vector<T> xs, ys;
  for (const auto &[l, d, r, u] : rect) {
    xs.push_back(l);
    xs.push_back(r);
    ys.push_back(d);
    ys.push_back(u);
  }
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  sort(begin(ys), end(ys));
  ys.erase(unique(begin(ys), end(ys)), end(ys));
  vector<vector<tuple<T, T, int>>> es(size(xs));
  for (const auto &[l, d, r, u] : rect) {
    auto pl = lower_bound(begin(xs), end(xs), l) - begin(xs);
    auto pd = lower_bound(begin(ys), end(ys), d) - begin(ys);
    auto pr = lower_bound(begin(xs), end(xs), r) - begin(xs);
    auto pu = lower_bound(begin(ys), end(ys), u) - begin(ys);
    es[pl].emplace_back(pd, pu, 1);
    es[pr].emplace_back(pd, pu, -1);
  }
  vector<Node> ini(size(ys)-1);
  for (int i = 0; i < (int)ini.size(); i++)
    ini[i] = {ys[i+1]-ys[i], ys[i+1]-ys[i], 0};
  SegTree seg(ini);
  ll res = 0;
  for (int i = 0; i < (int)size(es)-1; i++) {
    for (const auto &[d, u, o] : es[i]) seg.update(d, u-1, o);
    auto node = seg.query_all();
    if (!node.mn) node.len -= node.cnt;
    res += (ll)(xs[i+1] - xs[i]) * node.len;
  }
  return res;
}

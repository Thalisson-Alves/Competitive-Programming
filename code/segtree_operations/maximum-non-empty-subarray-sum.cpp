struct Node {
  ll pref, suff, sum, res; // res stores the answer
  Node() : Node(0ll) {}
  Node(ll x) : pref(x), suff(x), sum(x), res(x) {}
  Node(ll p, ll s, ll sm, ll mx) : pref(p), suff(s), sum(sm), res(mx) {}
};
Node op(Node a, Node b) {
  return {max(a.pref, a.sum + b.pref), max(b.suff, b.sum + a.suff), a.sum + b.sum, max({a.res, b.res, a.suff + b.pref})};
}

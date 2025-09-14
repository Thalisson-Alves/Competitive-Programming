// Given a binary array, find the length of the longest subarray with the same bit.
struct Node {
  int pref0, pref1, suff0, suff1, len, res;
  Node() : pref0(0), pref1(0), suff0(0), suff1(0), len(0), res(0) {}
  Node(bool x) : pref0(!x), pref1(x), suff0(!x), suff1(x), len(1), res(1) {}
};
Node op(const Node &a, const Node &b) {
  Node res;
  res.pref0 = a.pref0 + (a.pref0 == a.len ? b.pref0 : 0);
  res.pref1 = a.pref1 + (a.pref1 == a.len ? b.pref1 : 0);
  res.suff0 = b.suff0 + (b.suff0 == b.len ? a.suff0 : 0);
  res.suff1 = b.suff1 + (b.suff1 == b.len ? a.suff1 : 0);
  res.len = a.len + b.len;
  res.res = max({a.res, b.res, a.suff0+b.pref0, a.suff1+b.pref1});
  return res;
}

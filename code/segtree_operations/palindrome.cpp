int p1=31, p2=29, q1=(int)1e9+7, q2=(int)1e9+9;
using H = pair<int, int>;
H mul(H a, H b) { return {(ll)a.first*b.first%q1, (ll)a.second*b.second%q2}; }
H add(H a, H b) { return {(a.first+b.first)%q1, (a.second+b.second)%q2}; }
H power(int i) {
  static vector<H> pows{{1, 1}, {p1, p2}};
  while ((int)pows.size() <= i) pows.push_back(mul(pows.back(), pows[1]));
  return pows[i];
}
struct Node {
  int size;
  H s, rev; // is palindrome when s == rev
  Node() : size(0), s(), rev() {}
  Node(char c) : size(1), s({c%q1,c%q2}), rev(s) {}
  Node(int a, H b, H c) : size(a), s(b), rev(c) {}
};
Node op(Node a, [[maybe_unused]] Node b) {
  return {a.size + b.size, add(a.s, mul(b.s, power(a.size))), add(b.rev, mul(a.rev, power(b.size)))};
}

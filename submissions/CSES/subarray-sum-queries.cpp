#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T> struct SegTree {
  using Operation = T(*)(T, T);
 
  int N;
  vector<T> ns;
  Operation operation;
  T identity;
 
  SegTree(int n, Operation op = F(a+b), T neutral = T()) : N(n), ns(2 * N, neutral), operation(op), identity(neutral) {}
 
  SegTree(const vector<T> &v, Operation op = F(a+b), T neutral = T()) : SegTree((int)v.size(), op, neutral) {
    copy(v.begin(), v.end(), ns.begin() + N);
 
    for (int i = N - 1; i > 0; --i)
      ns[i] = operation(ns[2 * i], ns[2 * i + 1]);
  }
 
  T query(size_t i) const {
    return ns[i + N];
  }
 
  T query(size_t l, size_t r) const {
    auto a = l + N, b = r + N;
    auto ans = identity;
    // Non-associative operations needs to be processed backwards
    stack<T> st;
    while (a <= b) {
      if (a & 1)
        ans = operation(ans, ns[a++]);
      if (not (b & 1))
        st.push(ns[b--]);
 
      a >>= 1;
      b >>= 1;
    }
 
    for (; !st.empty(); st.pop())
      ans = operation(ans, st.top());
 
    return ans;
  }
 
  void update(size_t i, T value) {
    update_set(i, operation(ns[i + N], value));
  }
 
  void update_set(size_t i, T value) {
    auto a = i + N;
 
    ns[a] = value;
    while (a >>= 1)
      ns[a] = operation(ns[2 * a], ns[2 * a + 1]);
  }
};

struct Node {
  ll pref, suff, sum, res;

  Node() : Node(0ll) {}
  Node(ll x) : pref(x), suff(x), sum(x), res(x) {}
  Node(ll p, ll s, ll sm, ll mx) : pref(p), suff(s), sum(sm), res(mx) {}
};
 
void solve()
{
  int n, q;
  cin >> n >> q;

  SegTree<Node> st(n, F(Node(max(a.pref, a.sum + b.pref), max(b.suff, b.sum + a.suff), a.sum + b.sum, max({a.res, b.res, a.suff + b.pref}))));
  for (int i = 0; i < n; i++)
  {
    ll x;
    cin >> x;
    st.update_set(i, Node(x));
  }
  while (q--)
  {
    ll a, b;
    cin >> a >> b;
    --a;
    st.update_set(a, Node(b));
    cout << st.query(0, n-1).res << '\n';
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}

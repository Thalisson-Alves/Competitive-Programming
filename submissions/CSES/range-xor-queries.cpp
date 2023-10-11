#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T, auto op = [](T a, T b){return a+b;}, const T identity = T()>
struct SegTree {
  static_assert(std::is_convertible_v<decltype(op), std::function<T(T, T)>>,
                "Operation must be convertible to std::function<T(T, T)>");

  int N;
  vector<T> ns;

  SegTree(int n) : N(n), ns(2 * N, identity) {}

  SegTree(const vector<T> &v) : SegTree((int)v.size()) {
    copy(v.begin(), v.end(), ns.begin() + N);

    for (int i = N - 1; i > 0; --i)
      ns[i] = op(ns[2 * i], ns[2 * i + 1]);
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
        ans = op(ans, ns[a++]);
      if (not (b & 1))
        st.push(ns[b--]);

      a >>= 1;
      b >>= 1;
    }

    for (; !st.empty(); st.pop())
      ans = op(ans, st.top());

    return ans;
  }

  void update(size_t i, T value) {
    set(i, op(ns[i + N], value));
  }

  void set(size_t i, T value) {
    auto a = i + N;

    ns[a] = value;
    while (a >>= 1)
      ns[a] = op(ns[2 * a], ns[2 * a + 1]);
  }
};

struct Foo {
  ll operator()(ll a, ll b) const {
    return a ^ b;
  }
};

void solve()
{
  int n, q;
  cin >> n >> q;
  SegTree<ll, (Foo())> st(n);
 
  for (int i = 0, x; i < n and cin >> x; i++)
    st.set(i, x);
 
  for (ll a, b; cin >> a >> b;)
    cout << st.query(a-1, b-1) << '\n';
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
 
  return 0;
}


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
#define E(expr) []() { return expr; }
template <typename T, auto op, auto e>
struct SegTree {
  static_assert(std::is_convertible_v<decltype(op), std::function<T(T, T)>>,
                "op must be convertible to std::function<T(T, T)>");
  static_assert(std::is_convertible_v<decltype(e), std::function<T()>>,
                "e must be convertible to std::function<T()>");

  int N;
  vector<T> ns;

  SegTree(int n) : N(n), ns(2 * N, e()) {}

  SegTree(const vector<T> &v) : SegTree((int)v.size()) {
    copy(v.begin(), v.end(), ns.begin() + N);

    for (int i = N - 1; i > 0; --i)
      ns[i] = op(ns[2 * i], ns[2 * i + 1]);
  }

  T query(size_t i) const {
    return ns[i + N];
  }

  T query(size_t l, size_t r) const {
    l = l + N;
    r = r + N;

    auto ml = e(), mr = e();
    while (l <= r) {
      if (l & 1) ml = op(ml, ns[l++]);
      if (not (r & 1)) mr = op(ns[r--], mr);

      l >>= 1;
      r >>= 1;
    }

    return op(ml, mr);
  }

  void update(size_t i, T value) {
    update_set(i, op(ns[i + N], value));
  }

  void update_set(size_t i, T value) {
    auto a = i + N;

    ns[a] = value;
    while (a >>= 1)
      ns[a] = op(ns[2 * a], ns[2 * a + 1]);
  }
};

void solve()
{
  int n, q;
  cin >> n >> q;
 
  SegTree<pair<ll, ll>, F(make_pair(a.first+b.first, max(a.second, a.first + b.second))), E(make_pair(0ll,0ll))> st(n);
  for (int i = 0; i < n; i++)
  {
    ll x;
    cin >> x;
    st.update_set(i, make_pair(x, max(x, 0ll)));
  }
  while (q--)
  {
    int t;
    cin >> t;
    if (t == 1)
    {
      ll k, u;
      cin >> k >> u;
      --k;
      st.update_set(k, make_pair(u, max(u, 0ll)));
    }
    else
    {
      int a, b;
      cin >> a >> b;
      cout << st.query(a-1, b-1).second << '\n';
    }
  }
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


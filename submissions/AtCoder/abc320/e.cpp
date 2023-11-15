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
template <typename T>
struct SegTree {
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

    while (a <= b) {
      if (a & 1)
        ans = operation(ans, ns[a++]);
      if (not(b & 1))
        ans = operation(ans, ns[b--]);

      a /= 2;
      b /= 2;
    }

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

void solve()
{
  int n, m;
  cin >> n >> m;
  SegTree<int> st(n, F(min(a, b)), INT_MAX);
  for (int i = 0; i < n; i++)
    st.update_set(i, i);

  vector<ll> ans(n);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i = 0; i < m; i++) {
    ll t, w, s;
    cin >> t >> w >> s;

    while (pq.size() and pq.top().first <= t) {
      auto b = pq.top().second;
      pq.pop();

      st.update_set(b, b);
    }

    auto fst = st.query(0, n-1);
    if (fst == INT_MAX) continue;

    ans[fst] += w;
    st.update_set(fst, INT_MAX);
    pq.emplace(t + s, fst);
  }

  for (auto x : ans) cout << x << '\n';
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

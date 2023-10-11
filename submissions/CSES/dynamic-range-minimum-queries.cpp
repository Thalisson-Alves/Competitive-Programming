#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
 
template <typename T, T neutral = T(), typename operation_t = T (*)(T, T)>
struct SegTree {
  int N;
  vector<T> ns;
  operation_t operation;

  SegTree(int n, operation_t op) : N(n), ns(2 * N, neutral), operation(op) {}

  SegTree(const vector<T> &v, operation_t op) : SegTree((int)v.size(), op) {
    copy(v.begin(), v.end(), ns.begin() + N);

    for (int i = N - 1; i > 0; --i)
      ns[i] = operation(ns[2 * i], ns[2 * i + 1]);
  }

  T RQ(size_t l, size_t r) {
    auto a = l + N, b = r + N;
    auto ans = neutral;

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
  int n, q;
  cin >> n >> q;
  auto cmp = [](ll a, ll b){return min(a, b);};
  SegTree<ll, LLONG_MAX, decltype(cmp)> st(n, cmp);

  for (int i = 0, x; i < n and cin >> x; i++)
    st.update(i, x);

  for (ll t, a, b; cin >> t >> a >> b;)
  {
    if (t == 1)
      st.update_set(a-1, b);
    else
      cout << st.RQ(a-1, b-1) << '\n';
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'
#define all(x) x.begin(), x.end()

using ll = long long;

bool iter = false;
template <typename T, T neutral = T()> struct SegTree {
  typedef T (*operation_t)(const T &, const T &);
  // using operation_t = function<T(const T&, const T&)>;

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
    iter = false;
  }
};

void solve()
{
  int n, m;
  cin >> n >> m;

  auto op = [](const int&a, const int&b) -> int
  {
    return ((iter = not iter) ? a | b : a ^ b);
  };

  SegTree<int> st(1<<n, op);
  for (int i = 0, x; i < st.N and cin >> x; i++)
    st.update_set(i, x);

  for (int l, r; cin >> l >> r;)
  {
    st.update_set(l-1, r);
    cout << st.ns[1] << '\n';
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


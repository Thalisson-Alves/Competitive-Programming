#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

template<typename T>
struct BITree
{
  int N;
  vector<T> v;

  BITree(int n) : N(n), v(n+1, 0) {}

  void update(int i, const T& x)
  {
    if (i == 0) return;
    for (; i <= N; i += i & -i)
      v[i] += x;
  }

  T range_sum(int i, int j)
  {
    return range_sum(j) - range_sum(i - 1);
  }

  T range_sum(int i)
  {
    T sum = 0;
    for (; i > 0; i -= i & -i)
      sum += v[i];
    return sum;
  }
};

template <typename T>
// Query is of the form {L, R, K}
vector<T> elements_greater_than_k(const vector<T> &v, const vector<tuple<int, int, T>> &q) {
  struct Node {
    int pos, value, l, r;
  };

  int n = (int)v.size();
  int m = (int)q.size();
  vector<Node> a(n+m);
  for (int i = 0; i < n; i++) {
    a[i].pos = a[i].l = -1;
    a[i].r = i;
    a[i].value = v[i];
  }

  for (int j = 0; j < m; j++) {
    int i = j+n;
    auto [l, r, k] = q[j];
    a[i].pos = j;
    a[i].l = l;
    a[i].r = r;
    a[i].value = k;
  }

  sort(all(a), [](auto x, auto y) {
    if (x.value == y.value)
      return x.l > y.l;
    return x.value > y.value;
  });

  vector<int> ans(m);

  BITree<int> bit(n+m);
  for (int i = 0; i < n+m; i++) {
    // query
    if (a[i].pos != -1) {
      if (v[a[i].l-1] > a[i].value)
        ans[a[i].pos] = 0;
      else
        ans[a[i].pos] = bit.range_sum(a[i].l, a[i].r);
    } else {
      bit.update(a[i].r, 1);
    }
  }

  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (auto &x : v) cin >> x;

  vector<tuple<int, int, int>> q(m);
  for (auto &[l, r, k] : q) {
    cin >> l >> k >> r;
    r += l - 1;
    k--;
  }

  for (auto x : elements_greater_than_k(v, q))
    cout << x << '\n';
}

int32_t main()
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

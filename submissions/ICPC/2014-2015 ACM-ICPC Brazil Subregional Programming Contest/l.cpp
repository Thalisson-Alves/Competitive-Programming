#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

template<size_t Dim> struct GaussianElimination {
  using T = conditional_t<Dim <= 32, uint32_t, uint64_t>;
  vector<T> basis;

  void insert(T x) {
    for (const auto &b : basis)
      x = min(x, x ^ b);
    if (x) basis.push_back(x);
  }

  void merge(const GaussianElimination &other) {
    for (int i = 0; basis.size() < Dim and i < other.size(); i++)
      insert(other.basis[i]);
  }

  void normalize() {
    sort(basis.begin(), basis.end());
    for (int i = size() - 1; ~i; --i) {
      for (int j = i - 1; ~j; --j) {
        if (basis[i] & (1ll << (63 - __builtin_clzll(basis[j]))))
          basis[i] ^= basis[j];
      }
    }
  }

  bool check(T x) const {
    for (const auto &b : basis)
      x = min(x, x ^ b);
    return !x;
  }

  auto operator[](T k) const { return at(k); }
  int size() const { return (int) basis.size(); }

  // Need to call normalize() first
  T at(T k) const {
    T ans = 0;
    for (int i = 0; i <= size(); i++) {
      if (k & 1) ans ^= basis[i];
      k >>= 1;
    }
    return ans;
  }

  T max() const {
    T res = 0;
    for (const auto &b : basis)
      res = std::max(res, res ^ b);
    return res;
  }
};

void solve() {
  int n, k;
  cin >> n >> k;
  GaussianElimination<51> ge;
  for (int i = 0; i < n; i++) {
    ll value = 0;
    for (int j = 0; j < k; j++) {
      int x; cin >> x;
      if (x & 1) value |= 1ll << j;
    }
    ge.insert(value);
  }

  cout << "NS"[(k > ge.size()) or n <= k] << '\n';
}

// clang-format off
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

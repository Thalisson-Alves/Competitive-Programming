#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T, auto op> struct SegTree {
  static_assert(std::is_invocable_r_v<T, decltype(op), T, T>);

  int N;
  const T identity = T();
  vector<T> ns;

  SegTree(int n, const T identity_ = T()) : N(n), identity(identity_), ns(2 * N, identity)  {}

  SegTree(const vector<T> &v) : SegTree((int)v.size()) {
    copy(v.begin(), v.end(), ns.begin() + N);
    for (int i = N - 1; i > 0; --i)
      ns[i] = op(ns[2 * i], ns[2 * i + 1]);
  }

  T query(size_t i) const {
    return ns[i + N];
  }

  T query(size_t l, size_t r) const {
    auto ml = identity, mr = identity;
    for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) ml = op(ml, ns[l++]);
      if (not (r & 1)) mr = op(ns[r--], mr);
    }
    return op(ml, mr);
  }

  void update(size_t i, T value) {
    set(i, op(ns[i + N], value));
  }

  void set(size_t i, T value) {
    ns[i += N] = value;
    while (i >>= 1)
      ns[i] = op(ns[2 * i], ns[2 * i + 1]);
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> v(n);
  for (auto &x : v) cin >> x;
  vector<ll> pref(n+1);
  partial_sum(v.begin(), v.end(), pref.begin() + 1);
  vector<vector<pair<int, int>>> qs(n);
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    qs[--a].emplace_back(--b, i);
  }

  SegTree<ll, F(a+b)> sum(n + 1), hist(n + 1);
  // {v[i], qtdt}
  vector<pair<ll, int>> st;
  vector<ll> res(q);
  for (int i = n-1; ~i; --i) {
    pair<ll, int> nxt = {v[i], 1};
    while (!st.empty() and st.back().first < v[i]) {
      nxt.second += st.back().second;
      st.pop_back();
      sum.set(st.size(), 0);
      hist.set(st.size(), 0);
    }
    sum.set(st.size(), 1ll * nxt.first * nxt.second);
    hist.set(st.size(), nxt.second);
    st.push_back(nxt);

    for (auto [far, id] : qs[i]) {
      int l = 0, r = (int)st.size() - 1;
      while (l <= r) {
        auto mid = midpoint(l, r);
        if (hist.query(mid, n) <= (far - i + 1)) r = mid - 1;
        else l = mid + 1;
      }
      if (l < (int)st.size()) res[id] = sum.query(l, n);
      ll remain = (far - i + 1) - (l < (int)st.size() ? hist.query(l, n) : 0);
      if (remain) res[id] += remain * st[l-1].first;
      res[id] -= pref[far + 1] - pref[i];
    }
  }

  for (auto x : res) cout << x << '\n';
}

int32_t main() {
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

/*
 * A resposta para cada query é a soma dos valores de vetor_crescente[a..b] - vetor_original[a..b]
 * A medida que calculamos o vetor_crescente, é possível responder todas as query que começam em i
 * Para calcular o vetor_crescente podemos utilizar uma stack monótona
 * Depois fazer uma busca binária para encontrar o ponto onde a quantidade de elementos do vetor_crescente é suficiente para cobrir o intervalo da query
 * Com isso basta utilizar alguma estrutura para calcular a soma dos valores no range [l, r] da stack
 * Uma ideia muito legal é utilizar o tamanho da stack como índice para a estrutura de soma
*/

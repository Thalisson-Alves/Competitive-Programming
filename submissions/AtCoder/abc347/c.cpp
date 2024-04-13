#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

namespace rng {
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  uniform_real_distribution<double> dist(0.0, 1.0);

  inline void set_seed(int seed) { mt.seed(seed); }

  inline double next_double() { return dist(mt); }
  inline double next_double(double l, double r) {
    assert(l <= r);
    return l + next_double() * (r - l);
  }
  template<typename T, typename = typename enable_if<is_integral<T>::value>::type> inline T next_int(T r) {
    assert(r > 0);
    return T(mt() % r);
  }
  template<typename T, typename = typename enable_if<is_integral<T>::value>::type> inline T next_int(T l, T r) {
    assert(l <= r);
    return l + (T)(mt() % (r - l + 1));
  }

  template<typename T> inline void shuffle(vector<T> &v) {
    std::shuffle(v.begin(), v.end(), mt);
  }

  template<typename T> inline T choose(const vector<T> &v) { return v[next_int((int)v.size())]; }
  template<typename T> inline T choose(const initializer_list<T> &v) { return *next(v.begin(), next_int((int)v.size())); }

  template<typename T> inline vector<T> sample(const vector<T> &v, int k) {
    k = min(k, (int)v.size());
    vector<int> idx((int)v.size());
    iota(idx.begin(), idx.end(), 0);
    shuffle(idx);
    vector<T> ans(k);
    for (int i = 0; i < k; i++) ans[i] = v[idx[i]];
    return ans;
  }
}

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  const int tot = a + b;
  vector<int> d(n);
  for (auto &x : d) cin >> x;
  vector<int> all;
  {
    set<int> st;
    for (auto x : d) st.insert(x % tot);
    for (auto x : st) all.push_back(x);
    all = rng::sample(all, 100);
    all.push_back(*st.begin());
    all.push_back(*st.rbegin());
  }
  for (auto i : all) {
    bool s = true, e = true;
    for (auto x : d) {
      auto ds = (x - i) % tot;
      if (ds < 0) ds += tot;
      if (ds >= a) s = false;
      auto de = (x - i + a - 1) % tot;
      if (de < 0) de += tot;
      if (de >= a) e = false;
      if (!s and !e) break;
    }
    if (s or e) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
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

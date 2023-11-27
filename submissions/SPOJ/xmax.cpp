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

template<size_t Dim> struct GaussianElimination {
  vector<ll> basis;
  size_t size;

  GaussianElimination() : basis(Dim+1), size(0) {}

  void insert(ll x) {
    for (ll i = Dim; i >= 0; i--) {
      if ((x & 1ll << i) == 0) continue;

      if (!basis[i]) {
        basis[i] = x;
        size++;
        break;
      }

      x ^= basis[i];
    }
  }

  void normalize() {
    for (ll i = Dim; i >= 0; i--)
      for (ll j = i - 1; j >= 0; j--)
        if (basis[i] & 1ll << j)
          basis[i] ^= basis[j];
  }

  bool check(ll x) const {
    for (ll i = Dim; i >= 0; i--) {
      if ((x & 1ll << i) == 0) continue;

      if (!basis[i])
        return false;

      x ^= basis[i];
    }

    return true;
  }

  auto operator[](ll k) const { return at(k); }

  ll at(ll k) const {
    ll ans = 0;
    ll total = 1ll << size;
    for (ll i = Dim; ~i; i--) {
      if (!basis[i]) continue;

      ll mid = total >> 1ll;
      if ((mid < k and (ans & 1ll << i) == 0) ||
          (k <= mid and (ans & 1ll << i)))
        ans ^= basis[i];

      if (mid < k)
        k -= mid;

      total >>= 1ll;
    }
    return ans;
  }

  ll at_normalized(ll k) const {
    ll ans = 0;
    k--;
    for (size_t i = 0; i <= Dim; i++) {
      if (!basis[i]) continue;
      if (k & 1) ans ^= basis[i];
      k >>= 1;
    }
    return ans;
  }

  ll max() const {
    return at(1ll << size);
  }
};

void solve()
{
  GaussianElimination<63> ge;
  int n;
  cin >> n;
  while (n--) {
    ll x;
    cin >> x;
    ge.insert(x);
  }
  cout << ge.max() << '\n';
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

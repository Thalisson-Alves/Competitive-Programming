#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

template<size_t Dim>
struct GaussianElimination
{
  vector<ull> basis;
  size_t size;

  GaussianElimination() : basis(Dim+1), size(0) {}

  void insert(ll x)
  {
    for (ll i = Dim; i >= 0; i--)
    {
      if ((x & 1ll << i) == 0) continue;

      if (!basis[i])
      {
        basis[i] = x;
        size++;
        break;
      }

      x ^= basis[i];
    }
  }

  void normalize()
  {
    for (ll i = Dim; i >= 0; i--)
      for (ll j = i - 1; j >= 0; j--)
        if (basis[i] & 1ll << j)
          basis[i] ^= basis[j];
  }

  bool check(ll x)
  {
    for (ll i = Dim; i >= 0; i--)
    {
      if ((x & 1ll << i) == 0) continue;

      if (!basis[i])
        return false;

      x ^= basis[i];
    }

    return true;
  }

  auto operator[](ll k) { return at(k-1); }

  ull at1(ll k)
  {
    ull ans = 0;
    k--;
    for (ll i = 0; i <= (ll)Dim; i++)
    {
      if (!basis[i]) continue;

      if (k & 1) ans ^= basis[i];
      k >>= 1;
    }
    return ans;
  }

  ull at(ll k)
  {
    ull ans = 0;
    ll total = 1ll << size;
    for (ll i = Dim; i >= 0; i--)
    {
      if (!basis[i]) continue;

      auto mid = total >> 1ll;
      if ((k > mid and (ans & 1ll << i) == 0) ||
          (k <= mid and (ans & 1ll << i)))
        ans ^= basis[i];

      if (k > mid) k -= mid;
      total >>= 1ll;
    }
    return ans;
  }
};

void solve()
{
  ll n, l, r;
  cin >> n >> l >> r;

  GaussianElimination<60> ge;
  for (ll x; cin >> x; ge.insert(x));
  ge.normalize();

  // for (int i = 0; i <= 60; i++)
  //   if (ge.basis[i]) cerr << bitset<10>(ge.basis[i]) << '\n';

  for (; l <= r; l++)
    cout << ge.at1(l) << " \n"[l == r];
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


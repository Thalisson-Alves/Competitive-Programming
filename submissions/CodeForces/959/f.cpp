#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

struct GaussianElimination
{
  vector<ll> basis;
  size_t size;

  GaussianElimination(int k) : basis(k+1), size(0) {}

  void insert(ll x)
  {
    for (size_t i = 0; i < basis.size(); i++)
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

  bool check(ll x)
  {
    for (size_t i = 0; i < basis.size(); i++)
    {
      if ((x & 1ll << i) == 0) continue;

      if (!basis[i])
        return false;

      x ^= basis[i];
    }

    return true;
  }
};

void solve()
{
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  for (auto &x : v)
    cin >> x;

  map<int, vector<int>> queries;
  vector<pair<int, int>> qs(q);
  for (int i = 0; i < q; i++)
  {
    cin >> qs[i].first >> qs[i].second;
    queries[qs[i].first].push_back(i);
  }

  const ll MOD = 1e9 + 7;
  vector<ll> powers(n + 1);
  powers[0] = 1;
  for (int i = 0; i < n; i++)
    powers[i+1] = powers[i] * 2 % MOD;

  vector<ll> ans(q);
  GaussianElimination ge(20);
  for (int i = 0; i < n; i++)
  {
    ge.insert(v[i]);
    for (auto x : queries[i+1])
      if (ge.check(qs[x].second))
        ans[x] = powers[i+1 - ge.size];
  }
  for (int i = 0; i < q; i++)
    cout << ans[i] << "\n";
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


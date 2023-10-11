#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

map<ll, ll> factors(ll n)
{
  map<ll, ll> ans;
  for (ll i = 2; i*i <= n; i++)
  {
    ll count = 0;
    for (; n%i==0; count++, n/=i);
    if (count)
      ans[i] = count;
  }
  if (n > 1) ans[n]++;
  return ans;
}

ll sum(ll n) { return n*(n+1)/2; }

template<typename T, auto f, auto comp> inline T bin_bound(T x, T l = 0, T r = 1e18) {
  static_assert(std::is_convertible_v<decltype(f), std::function<T(T)>>,
                "f must be convertible to std::function<T(T)>");
  static_assert(std::is_convertible_v<decltype(comp), std::function<bool(T,T)>>,
                "comp must be convertible to std::function<bool(T,T)>");

  while (comp(l, r)) {
    auto mid = l + (r - l) / 2;
    if (comp(f(mid), x)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return r;
}

template<typename T, auto f> inline T lower_bound(T x, T l = 0, T r = 1e18) { return bin_bound<T, f, (less<T>())>(x, l, r); }
template<typename T, auto f> inline T upper_bound(T x, T l = 0, T r = 1e18) { return bin_bound<T, f, (less_equal<T>())>(x, l, r); }

void solve()
{
  ll n;
  cin >> n;
  auto f = factors(n);
  ll ans = 0;
  for (auto [p, x] : f) {
    ans += upper_bound<ll, sum>(x, 1, 10'000);
  }
  cout << ans << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

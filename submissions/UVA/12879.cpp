#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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

template<bool invert=false>
void fft(vector<complex<double>>& xs)
{
  int N = (int) xs.size();

  if (N == 1)
    return;

  vector<complex<double>> es(N/2), os(N/2);

  for (int i = 0; i < N/2; ++i)
    es[i] = xs[2*i];

  for (int i = 0; i < N/2; ++i)
    os[i] = xs[2*i + 1];

  fft<invert>(es);
  fft<invert>(os);

  auto signal = (invert ? 1 : -1);
  auto theta = 2 * signal * acos(-1) / N;
  complex<double> S { 1 }, S1 { cos(theta), sin(theta) };

  for (int i = 0; i < N/2; ++i)
  {
    xs[i] = (es[i] + S * os[i]);
    xs[i] /= (invert ? 2 : 1);

    xs[i + N/2] = (es[i] - S * os[i]);
    xs[i + N/2] /= (invert ? 2 : 1);

    S *= S1;
  }
}

void solve()
{
  for (int n; cin >> n;)
  {
    vector<int> ks(n);
    int mx_k = 0;
    for (auto &x : ks) cin >> x, mx_k = max(mx_k, x);
    int m;
    cin >> m;
    vector<int> ds(m);
    for (auto &x : ds) cin >> x;

    int size = 1;
    while (size <= 2*mx_k)
      size <<= 1;

    vector<complex<double>> v(size);
    v[0] = 1;
    for (auto x : ks)
      v[x] = 1;

    fft<false>(v);
    for (auto &x : v)
      x *= x;
    fft<true>(v);

    int ans = 0;
    for (auto d : ds)
      ans += (d < size and fabs(v[d].real()) > 1e-6);
    cout << ans << '\n';
  }
}

int main()
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
 

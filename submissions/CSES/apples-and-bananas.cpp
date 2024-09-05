#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

template <bool invert=false> void fft(vector<complex<double>> &a, const vector<int> &rev) {
  const static double pi = acos(-1);
  const int n = (int)a.size();
  for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int len = 2; len <= n; len <<= 1) {
    double angle = 2 * pi / len * (invert ? -1 : 1);
    complex<double> wlen(cos(angle), sin(angle));
    for (int i = 0; i < n; i += len) {
      complex<double> w(1);
      for (int j = 0; j < len / 2; j++) {
        complex<double> u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }

  if constexpr (invert) {
    for (auto &x : a)
      x /= n;
  }
}

template <typename T> vector<complex<double>> convolution(const vector<T> &a, const vector<T> &b) {
  vector<complex<double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  const int N = (int)(a.size() + b.size() - 1);
  int n = 1;
  while (n <= N) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  vector<int> rev(n);
  for (int i = 1; i < n; i++) {
    int bit = n >> 1;
    for (; rev.back() & bit; bit >>= 1) rev.back() ^= bit;
    rev.back() ^= bit;
    rev[i] = rev.back();
  }
  fft<false>(fa, rev);
  fft<false>(fb, rev);
  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  fft<true>(fa, rev);
  fa.resize(N);
  return fa;
}

void solve() {
  int k, n, m;
  cin >> k >> n >> m;
  vector<int> a(k+1), b(k+1);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a[x]++;
  }
  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    b[x]++;
  }
  auto c = convolution(a, b);
  for (int i = 2; i <= 2*k; i++) {
    cout << (ll)(roundl(c[i].real())) << " \n"[i==2*k];
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}

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
const vector<pair<int, int>> dir8{{1, 0},   {-1, 0}, {0, 1},  {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void solve() {
  ll n, p, h;
  cin >> n >> p >> h;

  using T = array<ll, 2>;

  vector<T> v;
  ll cima = (1ll << n) - h;
  ll baixo = h - 1;
  ll size = 1;

  v.push_back({cima, baixo});

  for (ll cur_pow = (1ll << (n - 1)), i = n; cur_pow; cur_pow >>= 1ll, --i) {
    if (baixo >= cur_pow) {
      ll tmp = cima;
      cima = baixo - cur_pow;
      baixo = tmp;
    } else {
      cima -= cur_pow;
    }
    size *= 2ll;
    v.push_back({cima, baixo});
  }

  reverse(all(v));
  size = (1ll << n);

  string ans;
  for (ll i = 0; i < n; i++) {
    ll side = p <= size / 2ll ? 0 : size / 2ll;
    if (v[i][1] < v[i + 1][1]) {
      p = size - p + 1;
      ans += "RL"[not side];
    } else {
      p -= side;
      ans += "LR"[not side];
    }
    size /= 2ll;
    if (p > size) p -= size;
  }
  
  cout << ans << '\n';
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

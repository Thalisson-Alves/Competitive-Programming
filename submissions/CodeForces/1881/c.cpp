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

void solve() {
  int n;
  cin >> n;
  vector<string> mat(n);
  for (auto &x : mat) cin >> x;
  auto original = mat;
  ll ans = 0;
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < n / 2; j++) {
      const auto values = {mat[i][j], mat[j][n-1-i], mat[n-1-i][n-1-j], mat[n-1-j][i]};
      auto mx = max(values);
      for (auto x : values) {
        ans += mx - x;
      }
    }
  }

  cout << ans << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

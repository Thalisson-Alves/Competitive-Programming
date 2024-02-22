#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

template<typename T, int D> struct Vec : public vector<Vec<T, D - 1>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template<typename... Args>
  Vec(int n = 0, Args... args) : vector<Vec<T, D - 1>>(n, Vec<T, D - 1>(args...)) {
  }
};
template<typename T>
struct Vec<T, 1> : public vector<T> {
  Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {
  }
};

using ll = long long;

void solve()
{
  int n, m;
  cin >> n >> m;
  constexpr auto cnt_power = [](int x) {
    array<int, 2> res = {0, 0};
    for (int i = 2; i <= 3; i++) {
      while (x % i == 0) {
        x /= i;
        ++res[i-2];
      }
    }
    return res;
  };
  Vec<int, 3> dp(n, m, (n + m) * 8, -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      auto [p2, p3] = cnt_power(x);
      if (i == 0 and j == 0) {
        dp[i][j][p3] = p2;
        continue;
      }
      for (int k = p3; k < (int)dp[i][j].size(); k++) {
        if (i and ~dp[i-1][j][k-p3])
          dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-p3] + p2);
        if (j and ~dp[i][j-1][k-p3])
          dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-p3] + p2);
      }
    }
  }
  int res = 0;
  for (int k = 0; k < (int)dp.back().back().size(); k++) {
    res = max(res, min(k, dp.back().back()[k]));
  }
  cout << res << '\n';
}

int32_t main() {
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

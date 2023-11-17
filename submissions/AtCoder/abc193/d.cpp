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

void solve()
{
  int k;
  cin >> k;
  string s, t;
  cin >> s >> t;

  vector<int> remain(10, k);
  for (int i = 0; i < 4; i++) remain[s[i]-'0']--;
  for (int i = 0; i < 4; i++) remain[t[i]-'0']--;

  constexpr auto eval = [](auto &a, int last) {
    auto prev = a.back();
    a.back() = (char)(last + '0');
    ll score = 0;
    for (int i = 1; i < 10; i++) {
      ll cnt = i;
      for (auto x : a) if (x == '0'+i) cnt *= 10;
      score += cnt;
    }
    a.back() = prev;
    return score;
  };

  double res = .0;
  for (int i = 1; i <= 9; i++) {
    if (remain[i]) {
      for (int j = 1; j <= 9; j++) {
        if ((i != j and remain[j]) or (i == j and remain[j] > 1)) {
          if (eval(s, i) > eval(t, j)) {
            dbg(i, j, remain[i], remain[j]);
            res += 1.0 * remain[i] / (k*9 - 8) * (i == j ? remain[j] - 1 : remain[j]) / (k*9 - 9);
          }
        }
      }
    }
  }
  cout << fixed << setprecision(6) << res << '\n';
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

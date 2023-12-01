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
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> c(h);
  for (auto &s : c) cin >> s;

  int res = 0;
  for (int i = 0; i < 1<<(h+w); i++) {
    vector<vector<char>> red(h, vector<char>(w));
    for (int j = 0; j < h+w; j++) if (i&(1<<j)) {
      if (j >= h) {
        for (int l = 0; l < h; l++) red[l][j-h] = 1;
      } else {
        for (int l = 0; l < w; l++) red[j][l] = 1;
      }
    }
    int black = 0;
    for (int j = 0; j < h; j++) {
      for (int l = 0; l < w; l++) {
        if (not red[j][l]) black += c[j][l] == '#';
      }
    }

    res += black == k;
  }
  cout << res << '\n';
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

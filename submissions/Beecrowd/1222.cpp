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
  for (int n, l, c; cin >> n >> l >> c;) {
    int curline = 0, curparagraph = 1;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;

      int x = (int)s.size();

      if (curline + x <= c) {
        curline += x + 1;
      } else {
        curline = x + 1;
        curparagraph += 1;
      }
    }

    cout << (curparagraph + l - 1) / l << '\n';
  }
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

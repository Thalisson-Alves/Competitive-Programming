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
  int a, b, c;
  cin >> a >> b >> c;

  auto can = [](int x, int y, int z) {
    while (x != y) {
      if (y < x) swap(x, y);
      if (z > 0)
        --z, --y, ++x;
      else if (x > 0 and y > 0)
        --y, --x, ++z;
      else break;
    }
    return x == y;
  };

  cout << can(b, c, a) << ' ' << can(a, c, b) << ' ' << can(a, b, c) << '\n';
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

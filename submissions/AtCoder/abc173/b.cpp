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
  int n;
  cin >> n;
  int a = 0, w = 0, t = 0, r = 0;
  while (n--) {
    string s;
    cin >> s;
    switch (s[0]) {
      case 'A': a++; break;
      case 'W': w++; break;
      case 'T': t++; break;
      case 'R': r++; break;
    }
  }
  cout << "AC x " << a << '\n';
  cout << "WA x " << w << '\n';
  cout << "TLE x " << t << '\n';
  cout << "RE x " << r << '\n';
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

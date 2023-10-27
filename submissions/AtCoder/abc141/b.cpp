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
const vector<pair<int, int>> dir8{{1, 0},   {-1, 0}, {0, 1},  {0, -1},
                                  {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void solve() {
  string s;
  cin >> s;
  for (int i = 0; i < (int)s.size(); i += 2) {
    if (s[i] == 'L') {
      cout << "No\n";
      return;
    }
  }

  for (int i = 1; i < (int)s.size(); i += 2) {
    if (s[i] == 'R') {
      cout << "No\n";
      return;
    }
  }

  cout << "Yes\n";
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

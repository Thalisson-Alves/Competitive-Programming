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
  if (n == 1) {
    cout << "N\n";
    return;
  }

  set<int> got;
  map<int, int> mp;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[x]++;
    got.insert(x);
    mx = max(mx, x);
  }

  for (int i = 0;; i++) {
    auto it = mp.find(i);
    if (it == mp.end()) continue;

    if (it->second > 1) {
      mp[i+1] += it->second / 2;
      got.insert(i+1);
    }

    if (it->second&1) {
      it->second = 1;
    } else {
      mp.erase(i);
    }

    if (mp.upper_bound(i) == mp.end()) {
      break;
    }
  }

  if (mp.size() > 2) {
    cout << "N\n";
  } else if (mp.size() == 2) {
    cout << "Y\n";
  } else if (got.count(mp.begin()->first-1)) {
    cout << "Y\n";
  } else {
    cout << "N\n";
  }
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

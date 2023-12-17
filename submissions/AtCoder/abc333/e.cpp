#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

void solve() {
  int n;
  cin >> n;
  vector<int> queries;
  unordered_map<int, int> pref;
  unordered_map<int, vector<int>> mp;
  vector<int> al, used(n);
  for (int i = 0; i < n; i++) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      mp[x].push_back(i);
      al.push_back(i);
    } else {
      auto &v = mp[x];
      if (v.empty()) {
        cout << "-1\n";
        return;
      }
      auto power = v.back();
      used[power] = 1;
      v.pop_back();

      queries.push_back(i);
      auto it = (int)(upper_bound(all(queries), power) - queries.begin());
      ++pref[it];
    }
  }

  int res = 0, sum = 0;
  for (int i = 0; i < (int)queries.size(); i++) {
    sum += pref[i];
    res = max(res, sum);
    --sum;
  }
  cout << res << '\n';
  for (auto x : al)
    cout << used[x] << ' ';
  cout << '\n';
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

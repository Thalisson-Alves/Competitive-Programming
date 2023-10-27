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
const vector<pair<int, int>> dir8{{1, 0},   {-1, 0}, {0, 1},  {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i;
  }

  sort(all(v));

  set<int> st;

  vector<ll> sum(n + 1);
  for (int i = n-1; ~i; --i) {
    auto it = st.insert(v[i].second).first;
    if (it != st.begin()) {
      --it;
      sum[(*it + v[i].second) / 2 + 1]++;
      sum[v[i].second]--;
      it++;
    } else {
      sum[0]++;
      sum[v[i].second]--;
    }

    if (++it != st.end()) {
      sum[v[i].second + 1]++;
      sum[(v[i].second + *it + 1) / 2]--;
    } else {
      sum[v[i].second+1]++;
      sum[n]--;
    }
  }

  ll res = 0;
  for (int i = 0; i < n; i++) {
    res += sum[i];
    cout << res << " \n"[i == n-1];
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

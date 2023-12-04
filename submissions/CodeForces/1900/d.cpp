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

vector<int> phi(1, 0);
vector<vector<int>> divs(1);
void phi_dp(int mx) {
  for (int i = 1; i <= mx; i++) {
    phi.push_back(i);
    divs.emplace_back(1, i);
  }
  for (int i = 1; i <= mx; i++) {
    for (int j = i+i; j <= mx; j+=i) {
      phi[j] -= phi[i];
      divs[j].push_back(i);
    }
  }
}

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  sort(all(a));

  vector<int> cnt(a.back()+1);

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (auto d : divs[a[i]]) {
      ans += ((n-1-i) * 1ll * phi[d] * cnt[d]);
      cnt[d]++;
    }
  }
  cout << ans << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  phi_dp(1e5);

  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

const ll oo = 1e18;

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

// solve(grid, i, j, n, m, dp);
ll solve(vector<string> &grid, int x, int y, int n, int m, vll2d &dp) {
  if (dp[x][y] != -1) return dp[x][y];

  ll ans = 1;
  for (int i = 0; i < 8; i++) {
    int x2 = x + dx[i];
    int y2 = y + dy[i];
    if (x2 < 0 or y2 < 0 or x2 >= n or y2 >= m) continue;
    if (grid[x2][y2] + 1 != grid[x][y]) continue;
    ans = max(ans, solve(grid, x + dx[i], y + dy[i], n, m, dp) + 1);
  }
  return dp[x][y] = ans;
}
void run() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (int i = 0; i < n; i++) cin >> grid[i];

  ll ans = 0;
  vll2d dp(n, vll(m, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans = max(ans, solve(grid, i, j, n, m, dp));
    }
  }

  cout << ans << endl;
}

int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

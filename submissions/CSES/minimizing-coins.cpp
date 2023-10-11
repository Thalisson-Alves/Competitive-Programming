#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<int, int>;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

template<typename T>
vector<T> split(const string &s)
{
  vector<T> ans;
  stringstream ss(s);
  for (T x; ss >> x; ans.push_back(x));
  return ans;
}

ll fpow(ll x, ll p)
{
  if (p == 0) return 1;
  auto ans = fpow(x, p >> 1);
  ans *= ans;
  if (p & 1) ans *= x;
  return ans;
}

int dp(const vector<int> &v, ll k, vector<int> &memo)
{
  if (memo[k]) return memo[k];
  if (k == 0) return 0;
  int ans = INT_MAX - 1;
  for (auto x : v)
  {
    if (k >= x)
      ans = min(ans, dp(v, k-x, memo));
  }
  return memo[k] = ans + 1;
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  vector<int> memo(k + 10);
  auto ans = dp(v, k, memo);
  cout << (ans == INT_MAX ? -1 : ans) << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}


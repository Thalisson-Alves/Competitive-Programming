#include <bits/stdc++.h>
#include <numeric>
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

template<typename T> vector<T> split(const string &s);
ll fpow(ll x, ll p);

int max_digit(int x)
{
  int ans = 0;
  while (x)
  {
    auto [d, m] = div(x, 10);
    ans = max(ans, m);
    x = d;
  }
  return ans;
}

ll dp(int x, vector<ll> &memo)
{
  if (memo[x]) return memo[x];
  if (x < 10) return 1;
  return memo[x] = 1 + dp(x - max_digit(x), memo);
}

void solve()
{
  int n;
  cin >> n;
  vector<ll> memo(n+1);
  cout << dp(n, memo) << '\n';
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

template<typename T> vector<T> split(const string &s)
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


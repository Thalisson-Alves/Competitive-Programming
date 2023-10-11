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

void solve()
{
  for (ll n, k; cin >> n >> k, n != -1 and k != -1;)
  {
    vector<ll> v(n+1);
    ll last = 0;
    for (int i = 0; i <= n; i++)
      cin >> v[i], last = (v[i] ? i : last);

    while (last >= k)
    {
      ll diff = last - k;
      v[diff] -= v[last];
      v[last] = 0;

      while (last >= k and v[last] == 0) last--;
    }

    int found = n;
    for (; ~found and not v[found]; found--);
    if (found == -1)
    {
      cout << "0\n";
      continue;
    }

    for (int i = 0; i <= found; i++)
      cout << v[i] << " \n"[i == found];
  }
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


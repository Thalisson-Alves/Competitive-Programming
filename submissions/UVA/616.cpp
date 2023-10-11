#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

vector<pair<int, int>> dir4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

vector<int> factors(int n)
{
  vector<int> ans;
  for (int i = 1; i * i <= n; i++)
  {
    auto dd = div(n, i);
    auto r = dd.rem, d = dd.quot;
    if (r != 0) continue;
    ans.push_back(i);
    if (d != i)
      ans.push_back(d);
  }

  sort(all(ans), greater<int>());
  return ans;
}

bool validate(int c, int p)
{
  for (int i = 0; i < p; i++)
  {
    if (c % p != 1) return false;

    c = c - c / p - 1;
  }
  return c % p == 0;
}

void solve()
{
  int n;
  cin >> n;
  if (n < 0) return;

  cout << n << " coconuts, ";

  int ans = 0;
  for (auto x : factors(n-1))
    if (validate(n, x))
    {
      ans = x;
      break;
    }

  if (ans)
    cout << ans << " people and 1 monkey\n";
  else
    cout << "no solution\n";

  solve();
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


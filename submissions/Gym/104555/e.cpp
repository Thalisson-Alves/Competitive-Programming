#include <bits/stdc++.h>
#include <type_traits>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define NDEBUG
#define dbg(...) 4269
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

int sum(int x)
{
  int sum = 0;
  while (x)
  {
    auto [d,m] = div(x, 10);
    sum += m;
    x = d;
  }
  return sum;
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> hist(1e6+1);
  for (int i =0 ; i < n; i++)
  {
    int x;
    cin >> x;
    hist[x]++;
  }
  int cur = 1e6;
  for (--k; cur and k; --cur)
  {
    auto dif = min(k, hist[cur]);
    if (dif < hist[cur]) break;
    k -= dif;
    hist[cur - sum(cur)] += dif;
  }
  while (not hist[cur]) cur--;
  cout << sum(cur) << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}

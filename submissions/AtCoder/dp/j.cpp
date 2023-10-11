#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

double value(int n, int ones, int twos, int threes, vector<vector<vector<double>>> &memo)
{
  int can = ones + twos + threes;
  if (can == 0)
    return 0.0;

  if (memo[ones][twos][threes] > 0) return memo[ones][twos][threes];

  double res = 1.0 * ((n - can) + can) / can;
  if (ones)
    res += value(n, ones - 1, twos, threes, memo) * ones / can;
  if (twos)
    res += value(n, ones + 1, twos - 1, threes, memo) * twos / can;
  if (threes)
    res += value(n, ones, twos + 1, threes - 1, memo) * threes / can;

  return memo[ones][twos][threes] = res;
}

void solve()
{
   int n;
   cin >> n;
   int ones = 0, twos = 0, threes = 0;
   for (int i = 0, x; i < n; i++)
   {
     cin >> x;
     ones += x == 1;
     twos += x == 2;
     threes += x == 3;
   }

   vector<vector<vector<double>>> memo(301, vector<vector<double>>(301, vector<double>(301, -1.0)));

   cout << fixed << setprecision(9) << value(n, ones, twos, threes, memo) << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}

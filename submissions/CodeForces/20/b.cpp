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

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

template <typename T>
int sign(T x)
{
  if (x == 0) return 0;
  return (x > 0 ? 1 : -1);
}
 
void solve()
{
  ll a, b, c;
  cin >> a >> b >> c;
  if (not (a | b | c))
    cout << "-1\n";
  else if (not (a | b))
    cout << "0\n";
  else if (not a)
  {
    cout << "1\n";
    cout << fixed << setprecision(7) << (-c / (double)b) << '\n';
  }
  else if (not (b | c))
  {
    cout << "1\n";
    cout << fixed << setprecision(7) << 0 << '\n';
  }
  else if (not (a | c))
  {
    cout << "1\n";
    cout << fixed << setprecision(7) << 0 << '\n';
  }
  else if (not b)
  {
    if (sign(c) == sign(a))
    {
      cout << "0\n";
      return;
    }

    double ans = sqrt(-c / (double) a);
    cout << "2\n";
    cout << fixed << setprecision(7) << -ans << '\n';
    cout << fixed << setprecision(7) << ans << '\n';
  }
  else if (not c)
  {
    double x1 = 0;
    double x2 = -b / (double)a;
    if (x1 > x2) swap(x1, x2);

    cout << "2\n";
    cout << fixed << setprecision(7) << x1 << '\n';
    cout << fixed << setprecision(7) << x2 << '\n';
  }
  else
  {
    ll delta = b*b - 4*a*c;
    if (delta < 0)
    {
      cout << "0\n";
      return;
    }

    double x1 = (-b - sqrt(delta)) / (2.0 * a);
    double x2 = (-b + sqrt(delta)) / (2.0 * a);
    if (x1 > x2) swap(x1, x2);

    cout << (delta == 0 ? 1 : 2) << "\n";
    cout << fixed << setprecision(7) << x1 << '\n';
    if (delta)
      cout << fixed << setprecision(7) << x2 << '\n';
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


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

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<int> ps(n);
  vector<set<int>> st(n);

  for (int i = 0; i< n; i++)
  {
    cin >> ps[i];
    int c;
    cin >> c;
    for (int j = 0; j < c; j++)
    {
      int x;
      cin >> x;
      st[i].insert(x);
    }

    for (int j = 0; j < i; j++)
    {
      if (includes(all(st[i]), all(st[j])) and (ps[i] < ps[j] or (ps[i] == ps[j] and st[i].size() > st[j].size())))
      {
        cout << "Yes\n";
        return;
      }
      if (includes(all(st[j]), all(st[i])) and (ps[j] < ps[i] or (ps[j] == ps[i] and st[j].size() > st[i].size())))
      {
        cout << "Yes\n";
        return;
      }
    }
  }
  cout << "No\n";
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
 

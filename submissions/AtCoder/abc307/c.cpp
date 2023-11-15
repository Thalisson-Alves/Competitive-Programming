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
ll oo = 1e18;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void solve()
{
  int h, w;
  cin >> h >> w;
  vector<string> as(h);
  for (auto &s : as) cin >> s;
  cin >> h >> w;
  vector<string> bs(h);
  for (auto &s : bs) cin >> s;
  cin >> h >> w;
  vector<string> xs(h);
  int tblack = 0;
  for (auto &s : xs)
  {
    cin >> s;
    for (auto c : s) tblack += c == '#';
  }
  vector<string> cca(10 + (as.size() + bs.size()), string(10 + (as[0].size() + bs[0].size()), '.'));
  for (int i = 0; i <= cca.size() - bs.size(); i++)
  {
    for (int j = 0; j <= cca[0].size() - bs[0].size(); j++)
    {
      for (int ii = 0; ii <= cca.size() - as.size(); ii++)
      {
        for (int jj = 0; jj <= cca[0].size() - as[0].size(); jj++)
        {

      auto ca = cca;
      dbg(ca);
      ll black = 0;
      for (int k = 0; k < bs.size(); k++)
        for (int l = 0; l < bs[0].size(); l++)
          if (ca[i+k][j+l] == '#' or bs[k][l] == '#')
            ca[i+k][j+l] = '#';
      for (int k = 0; k < as.size(); k++)
        for (int l = 0; l < as[0].size(); l++)
          if (ca[ii+k][jj+l] == '#' or as[k][l] == '#')
            ca[ii+k][jj+l] = '#';
      dbg(ca);
      for (int aa = 0; aa < ca.size(); aa++)
        for (int bb = 0; bb < ca[0].size(); bb++)
          black += ca[aa][bb] == '#';

      dbg(black, tblack);
      if (black != tblack) continue;

      for (int k = 0; k <= ca.size() - xs.size(); k++)
        for (int l = 0; l <= ca[0].size() - xs[0].size(); l++)
        {
          bool ok = true;
          for (int a = 0; ok and a < xs.size(); a++)
            if (xs[a] != ca[k+a].substr(l, xs[0].size()))
              ok = false;
          if (ok)
          {
            cout << "Yes\n";
            return;
          }
        }
        }
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


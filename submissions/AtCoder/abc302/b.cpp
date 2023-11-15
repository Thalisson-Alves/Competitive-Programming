#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

pair<string, vector<pair<int, int>>> get_s(vector<string> &v, int x, int y, int dx, int dy)
{
  string ans = "";
  vector<pair<int, int>> pos;
  for (int k = 0; k < 5; k++)
  {
    ans += v[x + k * dx][y + k * dy];
    pos.emplace_back(x + k * dx, y + k * dy);
  }

  return {ans, pos};
}

void solve()
{
  int h, w;
  cin >> h >> w;
  vector<string> v(h);
  for (auto &x : v) cin >> x;

  string sn = "snuke";
  string snr = "ekuns";
  vector<pair<int, int>> ans;
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (j <= w - 5)
      {
        auto [s, ps] = get_s(v, i, j, 0, 1);
        if (s == sn)
          ans = ps;
        else if (s == snr)
        {
          ans = ps;
          reverse(all(ans));
        }

        if (ans.size()) goto end;
      }
      if (i <= h - 5)
      {
        auto [s, ps] = get_s(v, i, j, 1, 0);
        if (s == sn)
          ans = ps;
        else if (s == snr)
        {
          ans = ps;
          reverse(all(ans));
        }

        if (ans.size()) goto end;
      }
      if (i <= h - 5 and j <= w - 5)
      {
        auto [s, ps] = get_s(v, i, j, 1, 1);
        if (s == sn)
          ans = ps;
        else if (s == snr)
        {
          ans = ps;
          reverse(all(ans));
        }

        if (ans.size()) goto end;
      }
      if (i <= h - 5 and j >= 5)
      {
        auto [s, ps] = get_s(v, i, j, 1, -1);
        if (s == sn)
          ans = ps;
        else if (s == snr)
        {
          ans = ps;
          reverse(all(ans));
        }

        if (ans.size()) goto end;
      }
    }
  }

end:
  for (auto [x, y] : ans)
    cout << x + 1 << ' ' << y + 1 << '\n';
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


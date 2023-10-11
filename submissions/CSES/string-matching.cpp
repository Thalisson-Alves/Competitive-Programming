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

vector<int> kmp_border(const string &p)
{
  int m = (int)p.size(), t = -1;
  vector<int> bs(m + 1, -1);

  for (int i = 1; i <= m; i++)
  {
    for (; t > -1 and p[t] != p[i - 1]; t = bs[t]);
    ++t;
    bs[i] = (i == m or p[t] != p[i]) ? t : bs[t];
  }

  return bs;
}

int kmp(const string &s, const string &p)
{
  int n = (int)s.size(), m = (int)p.size(), i = 0, j = 0, occ = 0;
  auto bs = kmp_border(p);

  while (i <= n - m)
  {
    for (; j < m and p[j] == s[i + j]; ++j);
    if (j == m) ++occ;

    int shift = j - bs[j];
    i += shift;
    j = max(0, j - shift);
  }

  return occ;
}

void solve()
{
  string s, p;
  cin >> s >> p;
  cout << kmp(s, p) << '\n';
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


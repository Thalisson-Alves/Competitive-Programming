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

vector<ll> is_pg(const vector<ll> &v)
{
  vector<ll> zeros;
  if (v.back() == 0) zeros.push_back(v.size() - 1);
  if (v.front() == 0) zeros.push_back(0);
  vector<ll> ans;
  for (int i = 1; i < (int)v.size()-1; i++)
  {
    if (v[i] == 0)
      zeros.push_back(i);
    if (v[i-1]*v[i+1] == v[i]*v[i])
      continue;

    if (ans.empty() or i-1 > ans.back())
      ans.push_back(i-1);
    ans.push_back(i);
    ans.push_back(i+1);
  }

  if (zeros.size() > 1)
  {
    ans.clear();
    for (int i = 1; i < (int)v.size(); i++)
      if (v[i])
        ans.push_back(i);
  }
  else if (zeros.size() and not (v[0] and zeros.size() == v.size() - 1))
    ans.push_back(zeros[0]);

  return ans;
}

void solve()
{
  int n;
  cin >> n;
  vector<ll> v(n);
  for (auto &x : v) cin >> x;

  auto wrong = is_pg(v);
  dbg(wrong);
  if (wrong.empty())
  {
    cout << "0\n";
    return;
  }

  if (wrong.size() > 11)
  {
    cout << "2\n";
    return;
  }

  wrong.push_back(0);
  wrong.push_back(n-1);

  for (auto x : wrong)
  {
    auto tmp = v;
    tmp.erase(tmp.begin() + x);
    dbg(x, tmp);
    if (is_pg(tmp).empty())
    {
      cout << "1\n";
      return;
    }
  }
  cout << "2\n";
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


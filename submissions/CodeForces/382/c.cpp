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

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

vector<ll> is_pa(const vector<ll> &v)
{
  vector<ll> ans;
  for (int i = 1; i < (int)v.size()-1; i++)
  {
    if (2*v[i]==v[i+1]+v[i-1])
      continue;

    if (ans.empty() or i-1 > ans.back())
      ans.push_back(i-1);
    if (ans.size() and i > ans.back())
      ans.push_back(i);
    ans.push_back(i+1);
  }
  return ans;
}

void solve()
{
  int n;
  cin >> n;
  vector<ll> v(n);
  for (auto &x : v) cin >> x;
  sort(all(v));
  if (n == 1)
  {
    cout << "-1\n";
    return;
  }
  if (n == 2)
  {
    auto dif = v.back() - v.front();
    if (dif == 0)
    {
      cout << "1\n" << v.back() << '\n';
      return;
    }
    cout << (!(dif&1) ? 3 : 2) << '\n';
    cout << v[0] - dif << ' ';
    if (!(dif&1)) cout << v[0] + dif/2 << ' ';
    cout << v[1] + dif << '\n';
    return;
  }

  auto wrong = is_pa(v);
  dbg(wrong);

  if (wrong.empty())
  {
    auto dif = v[1] - v[0];
    cout << (dif ? 2 : 1) << '\n';
    cout << v[0] - dif;
    if (dif) cout << ' ' << v.back() + dif;
    cout << '\n';
    return;
  }

  if (wrong.size() > 9)
  {
    cout << "0\n";
    return;
  }

  ll dif = v[1] - v[0];
  for (int i = 2; i < n; i++)
    dif = min(dif, v[i] - v[i-1]);

  wrong.push_back(n);
  set<ll> ans;
  for (auto x : wrong)
  {
    auto tmp = v;
    auto value = (x == n ? tmp[x-1]+dif : tmp[x] - dif);
    tmp.insert(tmp.begin()+x, value);
    if (is_pa(tmp).empty())
      ans.insert(value);
  }

  cout << ans.size() << '\n';
  bool first = true;
  for (auto x : ans)
  {
    if (not first) cout << ' ';
    cout << x;
    first = false;
  }
  cout << '\n';
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


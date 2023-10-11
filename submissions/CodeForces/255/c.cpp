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

void solve()
{
  int n;
  cin >> n;

  vector<int> v(n);
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
    mp[v[i]].push_back(i);
  }

  ll ans = 0;
  for (auto it = mp.begin(); it != mp.end(); it++)
  {
    ans = max(ans, (ll)it->second.size());
    for (auto in = next(it); in != mp.end(); in++)
    {
      ll sum = 1, next = (it->second[0] < in->second[0] ? 0 : 1);
      for (int i = 0, j = 0; i < (int)it->second.size() and j < (int)in->second.size();)
      {
        dbg(next, it->second[i], in->second[j], sum);
        if (next == 0 and it->second[i] > in->second[j])
        {
          j++;
          continue;
        }

        if (next == 1 and it->second[i] < in->second[j])
        {
          i++;
          continue;
        }

        (next ? j++ : i++);
        next = not next;
        sum++;
      }
      ans = max(ans, sum);
    }
  }
  cout << ans << '\n';
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


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
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  int n, k;
  cin >> n >> k;
  string s;
  cin>> s;
  vector<int> l(k), r(k);
  for (auto &x : l) cin >> x, --x;
  for (auto &x : r) cin >> x, --x;
  vector<set<int>> inter(k);
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    --x;
    auto it = upper_bound(all(l),x)-1-l.begin();
    auto &in = inter[it];

    x = min(x, r[it]+l[it]-x);
    {
      auto asdf = in.find(x);
      if (asdf != in.end()) {
        in.erase(asdf);
      } else {
        in.insert(x);
      }
    }
  }

  dbg(inter);
  dbg(l, r);

  for (int i = 0; i < k; i++) {
    bool flip = false;
    int cur = l[i];
    inter[i].insert((r[i]+l[i]+1)/2);
    for (auto x : inter[i]) {
      if (not flip) {
        cur = x;
        flip = 1;
        continue;
      }
      dbg(x, flip, cur);
      for (; cur < x and flip; cur++) {
        swap(s[cur], s[r[i]+l[i]-cur]);
        dbg(cur, r[i]+l[i]-cur);
        dbg(s[cur], s[r[i]+l[i]-cur]);
      }
      flip = not flip;
    }
    // dbg(flip, cur);
    // for (; 2*cur <= (r[i]+l[i]) and flip; cur++) {
    //   swap(s[cur], s[r[i]+l[i]-cur]);
    //   dbg(cur, r[i]+l[i]-cur);
    //   dbg(s[cur], s[r[i]+l[i]-cur]);
    // }
  }

  cout << s << '\n';
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}


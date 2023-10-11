#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

struct UFDS
{
  vector<int> ps, sz;
  int components;

  UFDS(int n) : ps(n), sz(n, 1), components(n)
  {
    iota(all(ps), 0);
  }

  int find_set(int x)
  {
    return (x == ps[x] ? x : (ps[x] = find_set(ps[x])));
  }

  bool same_set(int x, int y)
  {
    return find_set(x) == find_set(y);
  }

  void union_set(int x, int y)
  {
    x = find_set(x);
    y = find_set(y);
    
    if (x == y) return;

    if (sz[x] < sz[y])
      swap(x, y);

    ps[y] = x;
    sz[x] += sz[y];

    components--;
  }
};

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> con(n);
  vector<int> cnt(n);
  UFDS ufds(n);
  for (int i = 0; i < n; i++) {
    auto &x = a[i];
    cin >> x;
    --x;

    ufds.union_set(i,a[i]);
    con[i].push_back(x);
    cnt[x]++;
  }

  vector<set<int>> comps(n);
  for (int i =0 ; i< n ;i++) {
    comps[ufds.find_set(i)].insert(i);
  }

  vector<ll> c(n);
  for (auto &x : c) cin >> x;

  vector<bool> vis(n);
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (cnt[i] == 0) {
      q.push(i);
      vis[i] = 1;
    }
  }

  vector<int> ans;
  ans.reserve(n);
  for (int comp = 0; comp < n; comp++) {
    if (comp != ufds.find_set(comp)) continue;

loop:
    while (not q.empty()) {
      auto cur = q.front();
      q.pop();

      comps[ufds.find_set(cur)].erase(cur);

      for (auto x : con[cur]) {
        if (not vis[x] and --cnt[x] == 0) {
          q.push(x);
          vis[x] = 1;
        }
      }

      ans.push_back(cur);
    }

    if (comps[comp].empty()) continue;

    int mn = -1;
    for (auto i : comps[comp]) {
      if (mn == -1 or c[mn] > c[i]) {
        mn = i;
      }
    }

    q.push(a[mn]);
    vis[a[mn]] = 1;

    goto loop;
  }

  assert((int)ans.size() == n);

  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << " \n"[i == n-1];
  }
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
 
  return 0;
}


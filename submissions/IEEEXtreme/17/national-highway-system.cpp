#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

const vector<pair<int, int>> dir4{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vector<pair<int, int>> dir8{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

struct UFDS {
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

  bool union_set(int x, int y)
  {
    x = find_set(x);
    y = find_set(y);
    
    if (x == y) return false;

    if (sz[x] < sz[y])
      swap(x, y);

    ps[y] = x;
    sz[x] += sz[y];

    components--;
    return true;
  }
};

vector<tuple<ll, int, int>> kruskal(int n, vector<tuple<ll, int, int>> &edges)
{
  UFDS ufds(n);
  vector<tuple<ll, int, int>> ans;

  sort(all(edges));
  set<pair<int,int>> got;
  for (int i = 0; i < (int)edges.size(); i++)
  {
    auto [a, b, c] = edges[i];
    if (ufds.same_set(b, c))
      continue;

    for (int j = i + 1; j < (int)edges.size() and get<0>(edges[j]) == a; j++) {
      auto [na, nb, nc] = edges[j];
      if (!ufds.same_set(nb, nc) and got.emplace(minmax(nb,nc)).second)
        ans.emplace_back(na, nb, nc);
    }

    if (got.emplace(minmax(b,c)).second)
      ans.emplace_back(a, b, c);
    ufds.union_set(b, c);
  }

  if (ufds.components > 1)
    return {};

  return ans;
}

void solve()
{
  int n;
  cin >> n;
  int size = 0;
  unordered_map<string, int> mp;
  vector<tuple<ll, int, int>> edges;

  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    int w;
    cin >> w;

    auto [ia, ra] = mp.emplace(a, size);
    if (ra) size++;

    auto [ib, rb] = mp.emplace(b, size);
    if (rb) size++;

    edges.emplace_back(w, ia->second, ib->second);
    edges.emplace_back(w, ib->second, ia->second);
  }

  auto es = kruskal(size, edges);
  if (es.empty()) {
    cout << "-1\n";
    return;
  }

  ll ans = 0;
  for (auto [w, a, b] : es) {
    ans += w;
  }

  cout << ans << '\n';
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

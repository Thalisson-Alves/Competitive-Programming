#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int q;
  cin >> q;
  vector<list<int>> tree(1e5 + 2);
  vector<pair<int, list<int>::const_iterator>> parent(tree.size());
  parent[1] = {0, tree[0].insert(tree[0].end(), 1)};
  int id = 1;

  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      ++id;
      parent[id] = {x, tree[x].insert(tree[x].end(), id)};
    } else {
      auto [p, it] = parent[x];
      for (auto ch = tree[x].begin(); ch != tree[x].end(); ch++) {
        parent[*ch] = {p, tree[p].insert(it, *ch)};
      }
      tree[p].erase(it);
      cout << *tree[0].begin() << '\n';
    }
  }
}

int32_t main() {
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

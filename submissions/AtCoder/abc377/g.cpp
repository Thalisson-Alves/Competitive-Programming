#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T=char> struct Trie {
  struct Node {
    int size, min_remain;
    map<T, int> next;
  };
  vector<Node> nodes;
  Trie() : nodes(1) {}
  void add(const auto &v) {
    if (nodes[0].min_remain == 0) nodes[0].min_remain = (int)v.size();
    int u = 0;
    for (int i = 0; i < (int)v.size(); i++) {
      nodes[u].min_remain = min(nodes[u].min_remain, (int)v.size()-i);
      auto it = nodes[u].next.find(v[i]);
      if (it == nodes[u].next.end()) {
        nodes[u].next[v[i]] = (int)nodes.size();
        u = (int)nodes.size();
        nodes.emplace_back(i+1, (int)v.size()-i-1);
      } else {
        u = it->second;
      }
    }
    nodes[u].min_remain = 0;
  }
  void traverse_max_perfix(const auto &v, auto &&f) const {
    int u = 0;
    f(nodes[u]);
    for (auto x : v) {
      auto it = nodes[u].next.find(x);
      if (it == nodes[u].next.end()) break;
      u = it->second;
      f(nodes[u]);
    }
  }
};

void solve() {
  int n;
  cin >> n;
  Trie trie;
  while (n--) {
    string s;
    cin >> s;
    int res = (int)s.size();
    trie.traverse_max_perfix(s, [&](const auto &node) {
      res = min(res, (int)s.size() - node.size + node.min_remain);
    });
    cout << res << '\n';
    trie.add(s);
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}

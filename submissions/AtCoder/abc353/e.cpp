#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

struct Trie {
  struct Node {
    int value, size;
    map<char, shared_ptr<Node>> ch;

    Node() : value(0), size(0), ch() {}
  };

  shared_ptr<Node> root;

  Trie() : root(make_shared<Node>()) {}

  void insert(const string &x) {
    root->size++;
    auto cur = root;
    for (auto c : x) {
      auto it = cur->ch.insert({c, make_shared<Node>()}).first;
      cur = it->second;
      cur->size++;
    }
    cur->value++;
  }
};

void solve() {
  int n;
  cin >> n;
  Trie trie;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    trie.insert(s);
  }

  ll res = 0;
  auto dfs = [&](auto &&self, const auto &node) {
    if (node == nullptr or node->size <= 1) return;
    if (node != trie.root)
      res += 1ll * (node->size - 1) * (node->size) / 2;
    for (const auto &[_, x] : node->ch) {
      self(self, x);
    }
  };
  dfs(dfs, trie.root);

  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

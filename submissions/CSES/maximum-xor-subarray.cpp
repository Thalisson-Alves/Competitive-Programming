#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

template <typename T=ll> struct XorTrie {
  struct Node {
    T value;
    array<shared_ptr<Node>, 2> children;

    Node() : value(), children() {
      for (auto &x : children)
        x = shared_ptr<Node>(nullptr);
    }
  };

  shared_ptr<Node> root;

  XorTrie() : root(make_shared<Node>()) {}

  static constexpr int tsize() {
    if constexpr (is_same_v<int, T>) {
      return 31;
    } else {
      return 63;
    }
  }

  void insert(T x) {
    auto cur = root;
    for (int i = tsize(); ~i; --i) {
      auto &child = cur->children[x>>i&1];
      if (!child)
        child = make_shared<Node>();
      cur = child;
    }
    cur->value = x;
  }

  T query(T x) const {
    T res = 0;
    auto cur = root;
    for (int i = tsize(); ~i; --i) {
      int idx = x>>i&1;

      if (cur->children[idx^1]) {
        cur = cur->children[idx^1];
        res |= (T)1 << i;
      } else if (cur->children[idx]) {
        cur = cur->children[idx];
      }
    }
    return res;
  }
};

void solve() {
  int n;
  cin >> n;
  XorTrie<int> trie;
  trie.insert(0);
  int ans = INT_MIN, xr = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    xr ^= x;
    trie.insert(xr);
    ans = max(ans, trie.query(xr));
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

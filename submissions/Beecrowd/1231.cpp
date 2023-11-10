#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

struct Trie {
  int v[100005][2], cnt;
  bool is_end[200005];
  Trie() : cnt(1) {
    memset(v, 0, sizeof(v));
    memset(is_end, 0, sizeof(is_end));
  }

  void insert(const string &s) {
    int cur = 0;
    for (auto c : s) {
      int &nxt = v[cur][c - '0'];
      if (!nxt) nxt = cnt++;
      cur = nxt;
    }
    is_end[cur] = true;
  }

  int follow(int cur, bool c) const { return v[cur][c]; }
};

bool can(const Trie &a, int ca, const Trie &b, int cb, set<pair<int,int>> &vis) {
  if (a.is_end[ca] and b.is_end[cb]) return true;
  if (!vis.emplace(ca, cb).second) return false;

  if (a.is_end[ca] and can(a, 0, b, cb, vis)) return true;
  if (b.is_end[cb] and can(a, ca, b, 0, vis)) return true;

  for (int i = 0; i <= 1; i++) {
    auto na = a.follow(ca, i);
    auto nb = b.follow(cb, i);

    if (!na or !nb) continue;

    if (can(a, na, b, nb, vis)) return true;
  }
  return false;
}

void solve()
{
  set<pair<int, int>> vis;
  for (int n, m; cin >> n >> m;) {
    Trie a, b;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      a.insert(s);
    }
    for (int i = 0; i < m; i++) {
      string s;
      cin >> s;
      b.insert(s);
    }

    vis.clear();
    cout << "NS"[can(a, 0, b, 0, vis)] << '\n';
  }
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

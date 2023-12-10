#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;

struct SuffixAutomaton {
  struct state {
    int len, link, cnt, first_pos;
    map<char, int> next;
  };

  vector<state> st;
  vector<char> is_cloned;
  int sz, last;

  vector<ll> paths_dp;

  SuffixAutomaton(const string &s) : SuffixAutomaton(s, (int)s.size()<<1) {}
  SuffixAutomaton(const string &s, int maxlen) : st(maxlen), is_cloned(maxlen), sz(1), last(0), paths_dp(maxlen) {
    st[0].len = 0;
    st[0].link = -1;

    for (auto c : s) add(c);
    update_states_cnt();
  }

  void add(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].first_pos = st[cur].len - 1;
    int p = last;
    while (p != -1 and !st[p].next.count(c)) {
      st[p].next[c] = cur;
      p = st[p].link;
    }
    do {
      if (p == -1) {
        st[cur].link = 0;
        break;
      }
      int q = st[p].next[c];
      if (st[p].len + 1 == st[q].len) {
        st[cur].link = q;
        break;
      }
      int clone = sz++;
      is_cloned[clone] = true;
      st[clone].len = st[p].len + 1;
      st[clone].next = st[q].next;
      st[clone].link = st[q].link;
      st[clone].first_pos = st[q].first_pos;
      while (p != -1 and st[p].next[c] == q) {
        st[p].next[c] = clone;
        p = st[p].link;
      }
      st[q].link = st[cur].link = clone;
    } while (0);
    last = cur;
  }

  inline void update_states_cnt()
  {
    auto cmp = [&](int a, int b){return st[a].len < st[b].len;};
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for (int i = 1; i < sz; i++) {
      st[i].cnt = !is_cloned[i];
      pq.push(i);
    }

    for (; !pq.empty(); pq.pop()) {
      auto cur = pq.top();
      if (st[cur].link != -1)
        st[st[cur].link].cnt += st[cur].cnt;
    }
  }

  optional<state> find(const string &t) const {
    int cur = 0;
    for (auto c : t) {
      auto it = st[cur].next.find(c);
      if (it == st[cur].next.end()) return {};
      cur = it->second;
    }
    return st[cur];
  }

  inline bool is_substring(const string &t) const {
    return find(t).has_value();
  }

  inline int count(const string &t) const {
    if (auto s = find(t)) return s->cnt;
    else return 0;
  }

  inline int first_pos(const string &t) const {
    if (auto s = find(t)) return s->first_pos - (int)t.size() + 1;
    else return -1;
  }

  ll diff_substrings() const {
    ll res = 0;
    for (int i = 1; i < sz; i++)
      res += st[i].len - st[st[i].link].len;
    return res;
  }

  ll paths(int u) {
    auto &x = paths_dp[u];
    if (x) return x;
    x = 1;
    for (auto [_, v] : st[u].next)
      x += paths(v);
    return x;
  }

  // starts at 0
  string kth_substring(ll k) {
    string res;
    kth_substring(k, 0, res);
    return res;
  }

  void kth_substring(ll k, int at, string &res) {
    for (auto [c, v] : st[at].next) if (k >= 0) {
      if (paths(v) > k) {
        res += c;
        kth_substring(k-1, v, res);
        return;
      }
      k -= paths(v);
    }
  }
};

void solve() {
  string s;
  cin >> s;

  SuffixAutomaton sa(s);
  vector<ll> hs(sa.sz, -1);
  hs[0] = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    for (auto [_, v] : sa.st[u].next) if (hs[v] == -1) {
      q.push(v);
      hs[v] = hs[u] + 1;
    }
  }

  vector<int> res(s.size()+1);
  for (int i = 1; i < sa.sz; i++)
    ++res[hs[i]-1], --res[sa.st[i].len];

  cout << res[0];
  for (int i = 1; i < (int)s.size(); i++) {
    res[i] += res[i-1];
    cout << ' ' << res[i];
  }
  cout << '\n';
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

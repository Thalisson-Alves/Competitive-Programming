#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

struct SuffixAutomaton {
  struct state {
    int len, link, cnt, first_pos;
    map<char, int> next;
  };

  vector<state> st;
  vector<char> is_cloned;
  int sz, last;

  SuffixAutomaton(const string &s) : SuffixAutomaton(s, (int)s.size()<<1) {}
  SuffixAutomaton(const string &s, int maxlen) : st(maxlen), is_cloned(maxlen), sz(1), last(0) {
    st[0].len = 0;
    st[0].link = -1;

    for (auto c : s)
      add_char(c);

    update_states_cnt();
  }

  void add_char(char c) {
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
};

void solve()
{
  string s;
  cin >> s;

  SuffixAutomaton sa(s);

  int q;
  cin >> q;
  while (q--)
  {
    string t;
    cin >> t;

    cout << sa.count(t) << '\n';
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

/* Suffix Automaton
 *
 * Intuitively a suffix automaton can be understood as a compressed form of all substrings of a given string
 *
 * Fields:
 * - st: vector of states
 *   - len: length of the longest suffix in the subtree rooted at this state
 *   - link: suffix link
 *   - cnt: number of occurrences of the substring represented by the path from the root to this state
 *   - first_pos: position of the first occurrence of the substring represented by the path from the root to this state
 *   - repeated_cnt: number of substrings in the subtree rooted at this state
 *   - distinct_cnt: number of distinct substrings in the subtree rooted at this state
 *   - next: map from characters to the next states
 * - sz: number of states
 * - last: index of the last state
 *
 * Methods:
 * - add(char c): add a character to the automaton
 *   - Time: O(1) amortized
 * - find(const string &t): find the state corresponding to the substring t
 *   - Time: O(|t|)
 * - is_substring(const string &t): check if t is a substring
 *   - Time: O(|t|)
 * - count(const string &t): count the number of occurrences of t
 *   - Time: O(|t|)
 * - first_pos(const string &t): find the position of the first occurrence of t
 *   - Time: O(|t|)
 *   - Returns -1 if t is not a substring
 * - distinct_substrings(): count the number of distinct substrings
 *   - Time: O(n)
 * - distinct_substrings_by_size(): count the number of distinct substrings of each length
 *   - Time: O(n)
 * - kth_substring(ll k): find the k-th lexicographically smallest substring
 *   - Time: O(n)
 * - kth_distinct_substring(ll k): find the k-th lexicographically smallest distinct substring
 *   - Time: O(n)
 * - update_states_cnt(): update the cnt field of all states
 *   - Time: O(n*log(n))
 *   - Only needed to calculate the number of occurrences of a substring
 * - update_states_kth_counts(): update the distinct_cnt and repeated_cnt field of all states
 *   - Time: O(n)
 *   - Only needed to calculate the kth substring (distinct or not)
 */
struct SuffixAutomaton {
  struct state {
    int len, link, cnt, first_pos;
    ll repeated_cnt, distinct_cnt;
    map<char, int> next;
  };

  vector<state> st;
  int sz, last, n;

  SuffixAutomaton(const string &s) : SuffixAutomaton(s, (int)s.size()<<1) {}
  SuffixAutomaton(const string &s, int maxlen) : st(maxlen), sz(1), last(0), n(0) {
    st[0].len = 0;
    st[0].link = -1;

    for (auto c : s) add(c);
    update_states_cnt();
    update_states_kth_counts();
  }

  void add(char c) {
    ++n;
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].first_pos = st[cur].len - 1;
    st[cur].cnt = 1;
    int p = last;
    while (p != -1 and !st[p].next.count(c)) {
      st[p].next[c] = cur;
      p = st[p].link;
    }
    if (p == -1) {
      st[cur].link = 0;
    } else {
      int q = st[p].next[c];
      if (st[p].len + 1 == st[q].len) {
        st[cur].link = q;
      } else {
        int clone = sz++;
        st[clone].len = st[p].len + 1;
        st[clone].next = st[q].next;
        st[clone].link = st[q].link;
        st[clone].first_pos = st[q].first_pos;
        while (p != -1 and st[p].next[c] == q) {
          st[p].next[c] = clone;
          p = st[p].link;
        }
        st[q].link = st[cur].link = clone;
      }
    }
    last = cur;
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
    return find(t).value_or(state()).cnt;
  }

  inline int first_pos(const string &t) const {
    if (auto s = find(t)) return s->first_pos - (int)t.size() + 1;
    else return -1;
  }

  ll distinct_substrings() const {
    ll res = 0;
    for (int i = 1; i < sz; i++)
      res += st[i].len - st[st[i].link].len;
    return res;
  }
  vector<ll> distinct_substrings_by_size() const {
    vector<int> hs(sz, -1);
    hs[0] = 0;
    queue<int> q;
    q.push(0);
    int mx = 0;
    while (!q.empty()) {
      auto u = q.front(); q.pop();
      for (auto [_, v] : st[u].next) if (hs[v] == -1) {
        q.push(v);
        hs[v] = hs[u] + 1;
        mx = max(mx, st[v].len);
      }
    }

    vector<ll> res(mx);
    for (int i = 1; i < sz; i++) {
      ++res[hs[i]-1];
      if (st[i].len < mx)
        --res[st[i].len];
    }
    for (int i = 1; i < mx; i++)
      res[i] += res[i-1];
    return res;
  }

  // starts at 0
  string kth_substring(ll k) {
    k += n;
    string res;
    for (int u = 0; k >= st[u].cnt;) {
      k -= st[u].cnt;
      for (auto [c, v] : st[u].next) {
        if (st[v].repeated_cnt > k) {
          res += c; u = v;
          break;
        }
        k -= st[v].repeated_cnt;
      }
    }
    return res;
  }
  string kth_distinct_substring(ll k) {
    string res;
    for (int u = 0; k >= 0;) {
      for (auto [c, v] : st[u].next) {
        if (st[v].distinct_cnt > k) {
          res += c; --k; u = v;
          break;
        }
        k -= st[v].distinct_cnt;
      }
    }
    return res;
  }
  void update_states_cnt() {
    vector<pair<int, int>> order(sz-1);
    for (int i = 1; i < sz; i++) order[i-1] = {st[i].len, i};
    sort(rbegin(order), rend(order));
    for (auto [_, i] : order) st[st[i].link].cnt += st[i].cnt;
  }
  void update_states_kth_counts() {
    auto dfs = [&](auto &&self, int u) -> void {
      auto &dis = st[u].distinct_cnt;
      auto &rep = st[u].repeated_cnt;
      dis = 1;
      rep = st[u].cnt;
      for (auto [_, v] : st[u].next) {
        if (!st[v].distinct_cnt) self(self, v);
        dis += st[v].distinct_cnt;
        rep += st[v].repeated_cnt;
      }
    };
    dfs(dfs, 0);
  }
};

void solve() {
  string s; ll k;
  cin >> s >> k;
  SuffixAutomaton sa(s);
  cout << sa.kth_substring(--k) << '\n';
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

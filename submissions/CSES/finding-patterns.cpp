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
    int len, link;
    map<char, int> next;
  };

  vector<state> st;
  int sz, last;

  SuffixAutomaton(const string &s) : SuffixAutomaton(s, (int)s.size()<<1) {}
  SuffixAutomaton(const string &s, int maxlen) : st(maxlen), sz(1), last(0) {
    st[0].len = 0;
    st[0].link = -1;

    for (auto c : s)
      add_char(c);
  }

  void add_char(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
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
      st[clone].len = st[p].len + 1;
      st[clone].next = st[q].next;
      st[clone].link = st[q].link;
      while (p != -1 and st[p].next[c] == q) {
        st[p].next[c] = clone;
        p = st[p].link;
      }
      st[q].link = st[cur].link = clone;
    } while (0);
    last = cur;
  }

  bool is_substring(const string &p) const {
    int cur = 0;
    for (auto c : p) {
      auto it = st[cur].next.find(c);
      if (it == st[cur].next.end()) return false;
      cur = it->second;
    }
    return true;
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

    cout << (sa.is_substring(t) ? "YES" : "NO") << '\n';
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

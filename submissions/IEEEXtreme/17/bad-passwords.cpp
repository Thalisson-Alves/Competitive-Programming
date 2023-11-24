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

template <int p1=263, int q1=1000000007, int p2=257, int q2=1000000009>
struct HashString {
  vector<pair<int, int>> suf, powers;

  HashString(const string &s) : suf(s.size()+1), powers(s.size()+1) {
    powers[0] = {1, 1};
    powers[1] = {p1, p2};

    for (int i = (int)s.size()-1; ~i; --i) {
      suf[i].first = (int)((s[i] + (ll)suf[i+1].first * powers[1].first) % q1);
      suf[i].second = (int)((s[i] + (ll)suf[i+1].second * powers[1].second) % q2);
    }
    for (int i = 2; i <= (int)s.size(); i++) {
      powers[i].first = (int)((ll)powers[i-1].first * powers[1].first % q1);
      powers[i].second = (int)((ll)powers[i-1].second * powers[1].second % q2);
    }
  }

  bool operator<(const HashString &a) const {
    return hash() < a.hash();
  }

  pair<int, int> substr(int l) const {
    return substr(l, size()-1);
  }

  pair<int, int> substr(int l, int r) const {
    assert(0 <= l and l <= r and r < (int)suf.size() - 1);
    int a = (int)((((suf[l].first - (ll)suf[r+1].first * powers[r-l+1].first) % q1) + q1) % q1);
    int b = (int)((((suf[l].second - (ll)suf[r+1].second * powers[r-l+1].second) % q2) + q2) % q2);
    return {a, b};
  }

  int find(HashString &h, int p=0) const {
    if (p >= size()) return -1;
    for (int i = p; i+h.size()-1 < size(); i++) {
      if (substr(i, i+h.size()-1) == h.hash())
        return i;
    }
    return -1;
  }

  int max_prefix(const HashString &h) const {
    int l = 0, r = (int)min(size(),h.size())-1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (substr(0, mid) == h.substr(0, mid)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return l;
  }

  int max_suffix(const HashString &h) const {
    int l = 1, r = (int)min(size(),h.size());
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (substr(size()-mid) == h.substr(h.size()-mid)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return r;
  }

  pair<int, int> hash() const { return suf[0]; }

  int size() const { return (int)suf.size() - 1; }
};

void solve()
{
  int n;
  cin >> n;
  vector<vector<HashString<>>> v(n);
  vector<set<pair<int, int>>> hashes(n);
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    while (m--) {
      string s;
      cin >> s;
      v[i].emplace_back(s);
      hashes[i].insert(v[i].back().hash());
    }
  }
  int q;
  cin >> q;
  while (q--) {
    string a, b;
    cin >> a >> b;

    HashString ha(a), hb(b);

    auto mx_pref = ha.max_prefix(hb);

    for (int k = 0; k < n; k++) {
      for (auto &e : v[k]) {
        for (int i = max(mx_pref-11, 0); i <= mx_pref and i+e.size()-1 < ha.size(); i++) {
          if (ha.substr(i, i+e.size()-1) != e.hash()) continue;
          if (i+e.size() == ha.size() and hashes[k].count(hb.substr(i))) {
            cout << "REJECT\n";
            goto end;
          }
          int hb_suf = hb.size() - (ha.size()-i-e.size());
          if (ha.size() > i+e.size() and hb_suf-1 >= i and ha.substr(i+e.size()) == hb.substr(hb_suf) and hashes[k].count(hb.substr(i, hb_suf-1))) {
            cout << "REJECT\n";
            goto end;
          }
        }
      }
    }

    cout << "OK\n";
end:;
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

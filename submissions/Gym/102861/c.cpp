#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

template <int p1=31, int p2=29, int q1=1000000007, int q2=1000000009>
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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  using T = pair<int, int>;
  auto count_peculiar = [&]() -> int {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<HashString<>> va, vb;
    va.reserve(a.size());
    vb.reserve(b.size());
    map<T, int> sa, sb;
    for (int i = 0; i < n; i++) {
      va.emplace_back(a[i]);
      sa[va.back().hash()] = i;
    }
    for (int i = 0; i < m; i++) {
      vb.emplace_back(b[i]);
      sb[vb.back().hash()] = i;
    }
    map<T, int> dp;
    vector<bool> cnt(n, 1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (int)va[i].size() - 1; j++) {
        auto pref = va[i].substr(0, j);
        auto it = sa.find(pref);
        if (it == sa.end()) continue;
        auto suf = va[i].substr(j + 1);
        auto &f = dp[suf];
        for (auto k = upper_bound(b.begin(), b.end(), a[i].substr(j + 1)) - b.begin(); !f and k < (int)b.size() and (int)b[k].size() >= (int)a[i].size() - j and vb[k].substr(0, (int)a[i].size() - j - 2) == suf; k++) {
          if (!sb.count(vb[k].substr((int)a[i].size() - j - 1))) continue;
          f = 1;
        }
        if (!f) f = -1;

        if (~f) {
          cnt[i] = 0;
          cnt[it->second] = 0;
        }
      }
    }
    return accumulate(cnt.begin(), cnt.end(), 0);
  };

  auto ra = count_peculiar();
  for (auto &x : a) reverse(x.begin(), x.end());
  for (auto &x : b) reverse(x.begin(), x.end());
  swap(a, b);
  swap(n, m);

  auto rb = count_peculiar();

  cout << ra << ' ' << rb << '\n';
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

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

template <int p1=31, int q1=1000000007, int p2=29, int q2=1000000009>
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

bool is_match(int sz, int pref, int suff) {
  return (pref >= 3 and suff >= 3 and pref + suff >= sz);
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<string> dict(n);
  vector<HashString<>> hashes;
  map<pair<int, int>, vector<int>> pref3, suff3;
  for (int i = 0; i < n; i++) {
    cin >> dict[i];
    hashes.emplace_back(dict[i]);
    if (dict[i].size() >= 3) {
      pref3[hashes[i].substr(0, 2)].push_back(i);
      suff3[hashes[i].substr((int)dict[i].size()-3)].push_back(i);
    }
  }

  while (m--) {
    string s;
    cin >> s;
    HashString hs(s);
    if (s.size() < 5) {
      cout << "none\n";
      continue;
    }

    vector<pair<int, int>> pref(n), suff(n);
    for (auto i : pref3[hs.substr(0, 2)]) {
      pref[i].second = i;
      pref[i].first = hs.max_prefix(hashes[i]);
    }

    for (auto i : suff3[hs.substr(hs.size()-3)]) {
      suff[i].second = i;
      suff[i].first = hs.max_suffix(hashes[i]);
    }

    sort(all(pref), greater<>());
    sort(all(suff), greater<>());

    string ans;
    if (not is_match((int)s.size(), pref[0].first, suff[0].first)) {
      cout << "none\n";
    } else if (n > 1 and (is_match((int)s.size(), pref[1].first, suff[0].first) or is_match((int)s.size(), pref[0].first, suff[1].first))) {
      cout << "ambiguous\n";
    } else {
      cout << dict[pref[0].second] << ' ' << dict[suff[0].second] << '\n';
    }
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

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

  pair<int, int> substr(int l, int r) const {
    assert(0 <= l and l <= r and r < (int)suf.size() - 1);
    int a = (int)((((suf[l].first - (ll)suf[r+1].first * powers[r-l+1].first) % q1) + q1) % q1);
    int b = (int)((((suf[l].second - (ll)suf[r+1].second * powers[r-l+1].second) % q2) + q2) % q2);
    return {a, b};
  }

  pair<int, int> hash() const { return suf[0]; }
};

void solve()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  HashString hs(s);
  auto can = [&hs, &n](int mid) -> bool {
    map<pair<int,int>, int> mp;
    for (int i = 0; i+mid-1 < n; i++) {
      auto [it, ret] = mp.emplace(hs.substr(i, i+mid-1), i);
      if (not ret and i > it->second + mid - 1)
        return true;
    }
    return false;
  };

  int l = 1, r = n >> 1;
  while (l <= r) {
    auto mid = l + (r - l) / 2;
    if (can(mid)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << r << '\n';
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

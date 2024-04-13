#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  deque<int> v;
  multiset<int> s1, s2;
  ll sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> v.emplace_back();
    s1.insert(v.back());
    sum1 += v.back();
    while ((int)s1.size() > (k >> 1)) {
      sum2 += *s1.rbegin();
      sum1 -= *s1.rbegin();
      s2.insert(*s1.rbegin());
      s1.erase(prev(s1.end()));
    }
    if ((int)v.size() > k) {
      if (v.front() >= *s2.begin()) {
        sum2 -= v.front();
        s2.erase(s2.find(v.front()));
      } else {
        sum1 += *s2.begin() - v.front();
        sum2 -= *s2.begin();
        s1.erase(s1.find(v.front()));
        s1.insert(*s2.begin());
        s2.erase(s2.begin());
      }
      v.pop_front();
    }

    if ((int)v.size() == k) {
      cout << (*s2.begin() * s1.size() - sum1) + (sum2 - *s2.begin() * s2.size()) << ' ';
    }
  }
  cout << '\n';
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

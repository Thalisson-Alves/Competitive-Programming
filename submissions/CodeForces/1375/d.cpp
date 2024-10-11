#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

struct Mex {
  vector<int> hist;
  set<int> missing;
  Mex(int n) : hist(n) {
    for (int i = 0; i <= n; i++) missing.insert(i);
  }
  int operator()() const { return *begin(missing); }
  void add(int x) {
    if (x < (int)size(hist) and !hist[x]++)
      missing.erase(x);
  }
  void remove(int x) {
    if (x < (int)size(hist) and hist[x] and !--hist[x])
      missing.insert(x);
  }
};

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  Mex mex(n);
  for (auto &x : a) cin >> x, mex.add(x);
  set<int> wrong;
  for (int i = 0; i < n; i++) if (a[i] != i) wrong.insert(i);
  vector<int> res;
  while (size(wrong)) {
    int m = mex();
    int pos = m;
    if (m == n) pos = *wrong.begin();
    res.push_back(pos+1);
    mex.remove(a[pos]);
    mex.add(m);
    a[pos] = m;
    if (a[pos] == pos) wrong.erase(pos);
  }
  cout << size(res) << '\n';
  for (auto x : res) cout << x << ' ';
  cout << '\n';
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
}

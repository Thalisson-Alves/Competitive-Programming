#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> seq;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    seq.push_back(x);
    while (seq.size() >= 2 and seq[seq.size()-1] == seq[seq.size()-2]) {
      seq.pop_back();
      seq.back()++;
    }
  }
  cout << seq.size() << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

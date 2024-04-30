#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  string s;
  cin >> s;
  int res = INT_MAX;
  do {
    auto f = s.rfind('0');
    if (f == string::npos) break;
    auto l = s.rfind('0', f-1);
    if (l == string::npos) break;
    res = min(res, (int)(s.size() - 2 - f + s.size() - 1 - l));
  } while (0);
  do {
    auto f = s.rfind('2');
    if (f == string::npos) break;
    auto l = s.rfind('5');
    if (l == string::npos) break;
    int add = 0;
    if (!l) {
      for (int i = 1; i < (int)s.size() and s[i] == '0'; i++)
        add++;
    }
    if (f < (1 + (l < f))) {
      for (int i = (int)f+1; i < (int)s.size() and s[i] == '0'; i++)
        add++;
    }
    res = min(res, (int)(s.size() - 2 - f + s.size() - 1 - l + (l < f) + add));
  } while (0);
  do {
    auto f = s.rfind('5');
    if (f == string::npos) break;
    auto l = s.rfind('0');
    if (l == string::npos) break;
    res = min(res, (int)(s.size() - 2 - f + s.size() - 1 - l + (l < f)));
  } while (0);
  do {
    auto f = s.rfind('7');
    if (f == string::npos) break;
    auto l = s.rfind('5');
    if (l == string::npos) break;
    int add = 0;
    if (!l) {
      for (int i = 1; i < (int)s.size() and s[i] == '0'; i++)
        add++;
    }
    if (f < (1 + (l < f))) {
      for (int i = (int)f+1; i < (int)s.size() and s[i] == '0'; i++)
        add++;
    }
    res = min(res, (int)(s.size() - 2 - f + s.size() - 1 - l + (l < f) + add));
  } while (0);

  cout << (res == INT_MAX ? -1 : res) << '\n';
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

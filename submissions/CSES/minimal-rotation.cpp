#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

/* Returns the lexicographically smallest cyclic shift of a string.
 *
 * The cyclic shift of a string is a string that can be obtained by moving the
 * first few characters of the string to the end.
 * Example, the cyclic shifts of "abc" are "abc", "bca", and "cab".
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
*/
string min_cyclic_string(string &s) {
  s += s;
  int n = (int)size(s);
  int i = 0, res = 0;
  while (i < n / 2) {
    res = i;
    int j = i + 1, k = i;
    while (j < n && s[k] <= s[j]) {
      if (s[k] < s[j]) k = i;
      else k++;
      j++;
    }
    while (i <= k) i += j - k;
  }
  auto mn = s.substr(res, n / 2);
  s.resize(n / 2);
  return mn;
}

void solve() {
  string s;
  cin >> s;
  cout << min_cyclic_string(s) << '\n';
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

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

void solve() {
  int n;
  cin >> n;
  string t;
  cin >> t;
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    if (abs((int)s.size() - (int)t.size()) > 1) continue;

    int fd = -1;
    for (int j = 0; j < min((int)s.size(), (int)t.size()); j++)
      if (s[j] != t[j]) {
        fd = j;
        break;
      }

    if (fd == -1 and s.size() == t.size()) {
      ans.push_back(i);
      continue;
    } else if (fd == -1) {
      fd = min((int)s.size(), (int)t.size());
    }

    if (s.substr(0, fd) != t.substr(0, fd)) continue;

    if (s.size() < t.size() and s.substr(fd) == t.substr(fd+1)) {
      ans.push_back(i);
    }
    else if (s.size() > t.size() and s.substr(fd+1) == t.substr(fd)) {
      ans.push_back(i);
    }
    else if (s.size() == t.size() and s.substr(fd+1) == t.substr(fd+1)) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << '\n';
  for (int i = 0 ; i < (int)ans.size(); i++) {
    cout << ans[i] << " \n"[i == (int)ans.size()-1];
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

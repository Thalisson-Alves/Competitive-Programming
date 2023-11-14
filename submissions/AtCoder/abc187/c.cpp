#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

void solve()
{
  int n;
  cin >> n;
  unordered_map<string, bool> mp;
  for (int i =0; i < n; i++) {
    string s;
    cin >> s;
    bool t = true;
    if (s[0] == '!') t = false;
    s = t ? s : s.substr(1);
    auto it = mp.find(s);
    if (it == mp.end())
      mp[s] = t;
    else if (it->second != t) {
      cout << s << '\n';
      return;
    }
  }
  cout << "satisfiable\n";
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

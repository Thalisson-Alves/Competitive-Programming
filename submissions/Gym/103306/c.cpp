#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int) __x.size()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

const ll oo = 1e18;

void run() {
  string s;
  cin >> s;
  int cnt = 0, ans = -1, mx = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == 'R')
      cnt++;
    else
      cnt--;

    if (cnt > mx) {
      mx = cnt;
      ans = i;
    }
  }
  cout << ans + 1 << '\n';
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) run();
}

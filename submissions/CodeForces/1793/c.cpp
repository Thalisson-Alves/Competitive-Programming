#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'
#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<int, int>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  int n;
  cin >> n;
  vector<int> v(n);
  set<int> st;
  for (auto &x : v) cin >> x, st.insert(x);
  int l, r;
  for (l = 0, r = n - 1; l < r; )
  {
    auto mn = st.begin();
    auto mx = prev(st.end());
    if (v[l] == *mn or v[l] == *mx)
    {
      st.erase(v[l] == *mn ? mn : mx);
      l++;
    }
    else if (v[r] == *mn or v[r] == *mx)
    {
      st.erase(v[r] == *mn ? mn : mx);
      r--;
    }
    else
      break;
  }
  if (l == r)
    cout << "-1\n";
  else
    cout << l+1 << ' ' << r+1 << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}


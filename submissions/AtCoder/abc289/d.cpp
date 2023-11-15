#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n';
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
  vector<int> as(n);
  for (auto &x : as) cin >> x;
  int m;
  cin >> m;
  vector<int> bs(m);
  for (auto &x : bs) cin >> x;
  int t;
  cin >> t;
  vector<int> vall(t);
  for (auto x : bs) vall[x] = -1;

  stack<int> st;
  st.emplace(t);
  while (not vall[0] and not st.empty())
  {
    auto cur = st.top();
    st.pop();
    for (auto a : as)
      if (cur - a >= 0 and not vall[cur - a])
      {
        st.emplace(cur - a);
        vall[cur - a] = 1;
      }
  }
  cout << (vall[0] ? "Yes" : "No") << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  //cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}


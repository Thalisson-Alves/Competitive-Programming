#include <bits/stdc++.h>
using namespace std;

#define dff(x) " [" #x "]: "
#define df(x) dff(x) << (x)
#define dfn(x) df(x) << '\n'
#define dfv(_x) dff(_x); for (auto _y: _x) cerr << _y << ' '; cerr << '\n'
#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<ll, ll>;

template<typename T=int> inline T inf() { return numeric_limits<T>::max(); }

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<char> t(26);
  set<char> re, st;
  for (char i = 'a'; i <= 'z'; i++) st.insert(i);

  for (auto c : s)
  {
    int x = c - 'a';
    if (not t[x])
    {
      for (auto it = st.begin(); it != st.end(); it++)
      {
        bool can = *it != c;
        if (st.size() > 1)
          for (auto cur = t[*it - 'a']; can and cur; cur = t[cur - 'a'])
            if (cur == c)
              can = false;

        if (not can) continue;

        t[x] = *it;
        st.erase(it);
        break;
      }
    }

    cout << t[x];
  }
  cout << '\n';
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


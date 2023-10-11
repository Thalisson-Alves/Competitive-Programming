#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ii = pair<int, int>;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

void solve()
{
  for (int n; cin >> n, n != -1;)
  {
    string s;
    cin >> s;

    set<char> st(all(s));
    string guess;
    cin >> guess;
    cout << "Round " << n << "\n";
    int error = 0;
    for (auto c : guess)
    {
      if (error == 7) break;
      if (st.empty()) break;
      if (not st.count(c))
        error++;
      else
        st.erase(c);
    }

    if (st.empty())
      cout << "You win.\n";
    else if (error == 7)
      cout << "You lose.\n";
    else
      cout << "You chickened out.\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t;
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}


#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

int eval(pair<int, int> state, vector<vector<int>> &memo)
{
  if (memo[state.first][state.second] != -1) return memo[state.first][state.second];

  vector<char> seen(1000, 0);
  for (int i = 1; i <= state.first; i++)
  {
    pair<int, int> new_state = {state.first - i, state.second};
    if (new_state.first > new_state.second) swap(new_state.first, new_state.second);
    seen[eval(new_state, memo)] = 1;
  }
  for (int i = 1; i <= state.second; i++)
  {
    pair<int, int> new_state = {state.first, state.second - i};
    if (new_state.first > new_state.second) swap(new_state.first, new_state.second);
    seen[eval(new_state, memo)] = 1;
  }
  for (int i = 1; i <= min(state.first, state.second); i++)
  {
    pair<int, int> new_state = {state.first - i, state.second - i};
    if (new_state.first > new_state.second) swap(new_state.first, new_state.second);
    seen[eval(new_state, memo)] = 1;
  }

  int grundy = 0;
  while (seen[grundy]) grundy++;

  return memo[state.first][state.second] = grundy;
}

void solve()
{
  int n;
  cin >> n;
  vector<pair<int, int>> states(n);
  for (auto &[x, y] : states)
  {
    cin >> x >> y;
    if (x > y) swap(x, y);
  }
  // 0 - win, 1 - lose
  vector<vector<int>> values(101, vector<int>(101, -1));
  for (int i = 0; i <= 100; ++i)
    values[0][i] = values[i][i] = 999;

  int ans = 0;
  for (auto state : states)
  {
    dbg(state, eval(state, values));
    ans ^= eval(state, values);
  }

  cout << (ans ? 'Y' : 'N') << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();
 
  return 0;
}
 

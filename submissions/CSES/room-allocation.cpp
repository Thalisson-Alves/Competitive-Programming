#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif
 
#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;

const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};

void solve()
{
  int n;
  cin >> n;
  vector<tuple<int, int, int>> v(n);
  for (int i = 0; i < n; i++) {
    auto &[a, b, c] = v[i];
    cin >> a >> b;
    c = i;
  }
  sort(all(v));
  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
  set<int> free;
  for (int i = 1; i <= n; i++) free.insert(i);

  int rooms = 0;
  vector<int> ans(n);
  for (auto [a, b, c] : v) {
    if (not pq.empty() and pq.top().first < a) {
      free.insert(pq.top().second);
      pq.pop();
    }
    dbg(pq, a,b,c, free);
    ans[c] = *free.begin();
    pq.emplace(b, *free.begin());
    free.erase(free.begin());
    rooms = max(rooms, (int)pq.size());
  }
  cout << rooms << '\n';
  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n-1];
}

/*
2 3
7 7
5 6
1 2
7 9
2 6
10 10
5 7
8 9
10 10

2 - 3
2 - 7
1 - 6
1 - 2
1 - 9
3 - 6
2 - 10
4 - 7
*/

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}

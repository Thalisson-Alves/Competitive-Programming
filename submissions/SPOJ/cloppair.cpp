#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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

tuple<double, int, int> ans{INT_MAX, -1, -1};

struct point
{
  int x, y, idx;
};

bool cmp_x(const point &a, const point &b)
{
  return a.x < b.x or (a.x == b.x and a.y < b.y);
}

bool cmp_y(const point &a, const point &b)
{
  return a.y < b.y;
}

void update_ans(const point &a, const point &b)
{
  auto dist = hypot(a.x - b.x, a.y - b.y);
  if (dist < get<0>(ans))
    ans = {dist, a.idx, b.idx};
}

void nearest_points(vector<point> &v, int l, int r, vector<point> &t)
{
  if (r - l <= 3)
  {
    for (int i = l; i < r; i++)
      for (int j = i + 1; j < r; j++)
        update_ans(v[i], v[j]);
    sort(v.begin() + l, v.begin() + r, cmp_y);
    return;
  }

  int m = l + (r - l) / 2;
  int midx = v[m].x;
  nearest_points(v, l, m, t);
  nearest_points(v, m, r, t);

  merge(v.begin()+l, v.begin()+m, v.begin()+m, v.begin()+r, t.begin(), cmp_y);
  copy(t.begin(), t.begin() + r-l, v.begin()+l);

  int tsz = 0;
  for (int i = l; i < r; ++i)
  {
    if (abs(v[i].x - midx) >= get<0>(ans))
      continue;

    for (int j = tsz - 1; ~j and v[i].y - t[j].y < get<0>(ans); --j)
      update_ans(v[i], t[j]);
    t[tsz++] = v[i];
  }
}

void solve()
{
  int n;
  cin >> n;

  vector<point> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i].x >> v[i].y;
    v[i].idx = i;
  }

  sort(all(v), cmp_x);
  vector<point> t(n);

  nearest_points(v, 0, n, t);

  auto [d, a, b] = ans;
  if (a > b) swap(a, b);
  cout << a << ' ' << b << ' ' << fixed << setprecision(6) << d << '\n';
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
 

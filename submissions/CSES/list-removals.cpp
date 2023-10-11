#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

template<typename T>
struct BITree
{
    int N;
    vector<T> v;

    BITree(int n) : N(n), v(n+1, 0) {}

    void update(int i, const T& x)
    {
        if (i == 0) return;
        for (; i <= N; i += i & -i)
            v[i] += x;
    }

    T range_sum(int i, int j)
    {
        return range_sum(j) - range_sum(i - 1);
    }

    T range_sum(int i)
    {
        T sum = 0;
        for (; i > 0; i -= i & -i)
            sum += v[i];
        return sum;
    }
};

void solve()
{
  int n;
  cin >> n;
  BITree<int> st(n);
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  for (int i = 0; i < n; i++) st.update(i, 1);
  for (int i = 0; i < n; i++)
  {
    int x; cin >> x;
    --x;
    int l = 0, r = n-1;
    while (l <= r)
    {
      int m = l + (r-l)/2;
      if (st.range_sum(0, m) > x)
        r = m - 1;
      else
        l = m + 1;
    }
    cout << v[r] << ' ';
    st.update(l, -1);
  }
  cout << '\n';
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

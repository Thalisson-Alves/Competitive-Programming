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

void solve()
{
  ll x, n;
  cin >> x >> n;
  set<pair<ll, ll>> st{{0, x}};
  multiset<ll> dists{x};
  for (int i = 0; i < n; i++)
  {
    ll p;
    cin >> p;
    auto it = prev(st.upper_bound(make_pair(p, LLONG_MAX)));
    auto [a, b] = *it;
    dists.erase(dists.find(it->second - it->first));
    st.erase(it);

    dists.insert(p-a);
    dists.insert(b-p);

    st.emplace(a,p);
    st.emplace(p,b);

    cout << *dists.rbegin() << ' ';
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
  {
    // cout << "Caso " << i << ": ";
    solve();
  }
 
  return 0;
}


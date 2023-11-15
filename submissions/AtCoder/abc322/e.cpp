#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#include "./Competitive-Programming/debug.cpp"
#else
#define dbg(...)
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

constexpr int state_size = 6;
using state_t = array<int, state_size>;

ll dp(const auto &v, state_t products, int cur, ll memo[101][state_size][state_size][state_size][state_size][state_size]) {
  if(all_of(all(products), [](auto a){return a<=0;})) return 0;
  if(cur<0) return LLONG_MAX;
  auto &memod = memo[cur][products[1]][products[2]][products[3]][products[4]][products[5]];
  if (memod) return memod;

  ll ans = dp(v, products, cur-1, memo);
  auto next_p = products;
  for (int i=1;i<state_size;i++) {
    next_p[i]=max(0, next_p[i]-v[cur][i]);
  }
  auto cost = dp(v,next_p,cur-1, memo);
  products[0] = cur;
  return memod = (cost != LLONG_MAX ? min(ans,cost+v[cur][0]): ans);
}

void solve()
{
  ll n, k, p;
  cin >> n >> k >> p;
  vector<state_t> a(n);
  for (auto &x : a) {
    cin >> x[0];
    for (int i = 0; i < k; i++) cin >> x[i+1];
    for (int i = k; i < state_size-1; i++)  x[i+1] = 0;
  }

  state_t ps;
  ps[0]=0;
  for (int i = 1; i < state_size; i++) {
    if(i<=k) ps[i]=p;
    else ps[i]=0;
  }

  ll memo[101][state_size][state_size][state_size][state_size][state_size];
  auto ans= dp(a,ps,n-1, memo);
  cout << (ans==LLONG_MAX?-1:ans)<<'\n';
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }
 
  return 0;
}


#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 42
#endif

#define all(x) x.begin(), x.end()

using ll = long long;
using ull = unsigned long long;

vector<pair<int, int>> dir4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void solve()
{
  int n, q;
  cin >> n >> q;
  vector<tuple<ll, ll, ll>> v(n);
  for (auto &[a, b, c] : v) cin >> b >> c >> a;
  vector<ll> d(q);
  for (auto &x : d) cin >> x;

  sort(all(v));
  vector<tuple<ll, ll, bool>> events;
  for (auto [a, b, c]: v)
  {
    events.emplace_back(max(0ll, b-a), a, 0);
    events.emplace_back(max(0ll, c-a), a, 1);
  }
  sort(all(events));

  auto event = events.begin();
  multiset<ll> state;
  for (auto x : d)
  {
    for (; event != events.end() and get<0>(*event) <= x; event++)
    {
      if (get<2>(*event))
        state.erase(state.find(get<1>(*event)));
      else
        state.insert(get<1>(*event));
    }
    cout << (state.empty() ? -1 : *state.begin()) << '\n';
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


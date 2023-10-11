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

const double p = 0.2316419;
const double PI = acos(-1.0);
const double B[] = {0.319381530, -0.356563782, 1.781477937, -1.821255978, 1.330274429};

vector<pair<int, int>> dir4{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

template<size_t N = 31>
ull nth_set(ull value, ull mask)
{
  for (ull i = 0, j = 0, zs = 0; i <= N; i++)
  {
    if ((mask & (1ull << i)) == 0) continue;
    for (; j < N and zs <= i; j++)
      zs += !(value & (1ull << j));

    value |= 1ull << (j-1);
  }

  return value;
}

void solve()
{
  for (ull n, l, u; cin >> n >> l >> u;)
  {
    ull base = 0, ans = l;
    for (ll j = 31; ~j; j--)
    {
      ull cur = base;
      if ((n & (1ull << j)) or (cur | (1ull << j)) > u) continue;
      cur |= 1ull << j;

      bool can = false;
      ull count = 31 - __builtin_popcount((unsigned)cur);
      ll ml = 0, mr = (1ull << count) - 1;
      while (ml <= mr)
      {
        ull msk = ml + (mr - ml) / 2;

        ull tmp = nth_set<31>(cur, msk);

        if (l <= tmp)
        {
          mr = msk - 1;
          if (tmp <= u)
          {
            can = true;
            ans = tmp;
          }
        }
        else
          ml = msk + 1;
      }

      if (can)
        base = cur;
    }

    cout << ans << '\n';
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


#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  using pt = array<ll, 2>;
  vector<pt> ps(n);
  for (auto &[a, b] : ps) cin >> a >> b;
  int m;
  cin >> m;
  vector<pt> ops(m);
  for (auto &[a, b] : ops) {
    cin >> a; if (a > 2) cin >> b;
  }
  int q;
  cin >> q;
  vector<array<int, 3>> qs(q);
  for (int i = 0; i < q; i++) {
    cin >> qs[i][0] >> qs[i][1];
    --qs[i][1];
    qs[i][2] = i;
  }
  sort(qs.rbegin(), qs.rend());

  array<ll, 9> mat = {1, 0, 0, 0, 1, 0, 0, 0, 1};
#define rotate(f) mat = {f * mat[3], f * mat[4], f * mat[5],\
                         -f * mat[0], -f * mat[1], -f * mat[2],\
                         mat[6], mat[7], mat[8]};
#define mirror(d, f) mat = {f*mat[0] + (f==-1)*2*d*mat[6], f*mat[1]+(f==-1)*2*d*mat[7], f*mat[2]+(f==-1)*2*d*mat[8],\
                            -f*mat[3]+(f==1)*2*d*mat[6], -f*mat[4]+(f==1)*2*mat[7], -f*mat[5]+(f==1)*2*d*mat[8],\
                            mat[6], mat[7], mat[8]};

  auto apply = [&](const pt &p) -> pt {
    return {mat[0] * p[0] + mat[1] * p[1] + mat[2], mat[3] * p[0] + mat[4] * p[1] + mat[5]};
  };

  vector<pt> res(q);
  for (; !qs.empty() and qs.back()[0] == 0; qs.pop_back()) {
    res[qs.back()[2]] = ps[qs.back()[1]];
  }
  for (int i = 0; i < m and qs.size(); i++) {
    if (ops[i][0] == 1) {
      rotate(1)
    } else if (ops[i][0] == 2) {
      rotate(-1);
    } else if (ops[i][0] == 3) {
      mirror(ops[i][1], -1);
    } else {
      mirror(ops[i][1], 1);
    }

    for (; !qs.empty() and qs.back()[0]-1 == i; qs.pop_back()) {
      res[qs.back()[2]] = apply(ps[qs.back()[1]]);
    }
  }

  for (auto [a, b] : res)
    cout << a << ' ' << b << '\n';
}

int32_t main() {
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

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

template <typename T>
struct Mo {
  struct Query {
    int l, r, idx, block;

    Query(int _l, int _r, int _idx, int _block) : l(_l), r(_r), idx(_idx), block(_block) {}

    bool operator<(const Query &q) const {
      if (block != q.block) return block < q.block;
      return (block & 1 ? (r < q.r) : (r > q.r));
    }
  };

  vector<T> vs;
  vector<Query> qs;
  const int block_size;

  Mo(const vector<T> &a) : vs(a), block_size((int)ceil(sqrt(a.size()))) {}

  void add_query(int l, int r) {
    qs.emplace_back(l, r, qs.size(), l / block_size);
  }

  auto solve() {
    vector<typename result_of<decltype(&Mo::get_answer)(Mo)>::type> answers(qs.size());
    sort(all(qs));

    int cur_l = 0, cur_r = -1;
    for (auto q : qs) {
      while (cur_l > q.l) add(--cur_l);
      while (cur_r < q.r) add(++cur_r);
      while (cur_l < q.l) remove(cur_l++);
      while (cur_r > q.r) remove(cur_r--);
      answers[q.idx] = get_answer();
    }

    return answers;
  }

private:
  vector<int> mp = vector<int>(2e5+1);
  int dis = 0;
  // add value at idx from data structure
  inline void add(int idx) {
    dis += (mp[vs[idx]]++ == 0);
  }

  // remove value at idx from data structure
  inline void remove(int idx) {
    dis -= (--mp[vs[idx]] == 0);
  }

  // extract current answer of the data structure 
  inline auto get_answer() {
    return dis;
  }
};
 
void solve()
{
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  map<int, int> comp;
  int comp_value = 1;
  for (auto &x : a) {
    cin >> x;
    if (comp.find(x) != comp.end())
      x = comp[x];
    else {
      comp[x] = comp_value;
      x = comp_value++;
    }
  }

  Mo mo(a);
  while (q--) {
    int l, r;
    cin >> l >> r;
    mo.add_query(l-1, r-1);
  }

  for (auto x : mo.solve())
    cout << x << '\n';
}

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

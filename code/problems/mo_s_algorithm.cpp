struct Mo {
  struct Query {
    int l, r, idx, block;
    Query(int _l, int _r, int _idx, int _block) : l(_l), r(_r), idx(_idx), block(_block) {}
    bool operator<(const Query &q) const {
      if (block != q.block) return block < q.block;
      return (block & 1 ? (r < q.r) : (r > q.r));
    }
  };
  vector<Query> qs;
  const int block_size;
  // number of elements in the array
  Mo(int n) : block_size((int)ceil(sqrt(n))) {}
  void add_query(int l, int r) {
    qs.emplace_back(l, r, qs.size(), l / block_size);
  }
  void solve(auto &&add, auto &&remove, auto &&answer) {
    sort(qs.begin(), qs.end());
    int cur_l = 0, cur_r = -1;
    for (auto q : qs) {
      while (cur_l > q.l) add(--cur_l);
      while (cur_r < q.r) add(++cur_r);
      while (cur_l < q.l) remove(cur_l++);
      while (cur_r > q.r) remove(cur_r--);
      answer(q.idx);
    }
  }
};

#define F(expr) [](auto a, auto b) { return expr; }
template <typename T, const T neutral = T()>
struct DisjointSparseTable
{
  using Operation = T(*)(T, T);

  vector<vector<T>> st;
  const Operation f;

  static constexpr int log2_floor(unsigned long long i) noexcept { return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1; }

  DisjointSparseTable(vector<T> v) : DisjointSparseTable(v, F(a+b)) { }

  DisjointSparseTable(vector<T> v, Operation op) : st(log2_floor(v.size())+1, vector<T>(1ll << (log2_floor(v.size())+1))), f(op)
  {
    v.resize(st[0].size(), neutral);
    for (int level = 0; level < (int)st.size(); ++level)
    {
      for (int block = 0; block < (1 << level); ++block)
      {
        const auto l = block << (st.size() - level);
        const auto r = (block + 1) << (st.size() - level);
        const auto m = l + (r - l) / 2;

        st[level][m] = v[m];
        for (int i = m + 1; i < r; i++)
          st[level][i] = f(st[level][i-1], v[i]);
        st[level][m-1] = v[m-1];
        for (int i = m-2; i >= l; i--)
          st[level][i] = f(st[level][i+1], v[i]);
      }
    }
  }

  T query(int l, int r) const
  {
    if (l > r) return neutral;
    if (l == r) return st.back()[l];

    const auto k = log2_floor(l^r);
    const auto level = (int)st.size() - 1 - k;
    return f(st[level][l], st[level][r]);
  }
};

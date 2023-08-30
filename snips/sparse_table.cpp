#define F(expr) [](auto a, auto b) { return expr; }
template <typename T, const T neutral = T()>
struct SparseTable
{
  using Operation = T(*)(T, T);

  const int LOGN;
  vector<vector<T>> st;
  Operation f;

  static constexpr int log2_floor(unsigned long long i) noexcept { return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1; }

  SparseTable(const vector<T> &v, Operation op) : LOGN(log2_floor(v.size())), st(LOGN+1, vector<T>(v.size())), f(op)
  {
    st[0] = v;
    for (int i = 1; i <= LOGN; i++)
      for (int j = 0; j + (1 << i) <= (int)v.size(); j++)
        st[i][j] = f(st[i-1][j], st[i-1][j+(1 << (i-1))]);
  }

  SparseTable(const vector<T> &v) : SparseTable(v, F(min(a,b))) { }

  T query(int l, int r) const
  {
    T acc = neutral;
    for (int i = LOGN; ~i; --i)
      if ((1 << i) <= r - l + 1)
      {
        acc = f(acc, st[i][l]);
        l += 1 << i;
      }
    return acc;
  }

  T RMQ(int l, int r) const
  {
    auto lg = log2_floor(r-l+1);
    return f(st[lg][l], st[lg][r - (1 << lg) + 1]);
  }
};

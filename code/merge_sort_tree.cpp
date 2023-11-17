template <typename T>
struct MergeSortTree {
  int N;
  vector<vector<T>> v;

  MergeSortTree(const vector<T> &a) : N((int)a.size()), v(4 * N) {
    build(a, 1, 0, N-1);
  }

  int query(int l, int r, T mn, T mx) const {
    return query(1, 0, N-1, l, r, mn, mx);
  }
private:
  void build(const vector<T> &a, int node, int tl, int tr) {
    if (tl == tr) {
      v[node] = {a[tl]};
    } else {
      auto tm = tl + (tr - tl) / 2;
      build(a, 2*node, tl, tm);
      build(a, 2*node+1, tm+1, tr);
      merge(all(v[2*node]), all(v[2*node+1]), back_inserter(v[node]));
    }
  }

  int query(int node, int tl, int tr, int l, int r, T mn, T mx) const {
    if (r < tl or tr < l) return T();
    if (l <= tl and tr <= r) {
      return (int)(lower_bound(all(v[node]), mx) - lower_bound(all(v[node]), mn));
    }

    auto tm = tl + (tr - tl) / 2;
    return query(2*node, tl, tm, l, r, mn, mx) + query(2*node+1, tm+1, tr, l, r, mn, mx);
  }
};

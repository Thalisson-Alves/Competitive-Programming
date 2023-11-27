vector<tuple<ll, int, int>> kruskal(int n, vector<tuple<ll, int, int>> &edges) {
  UFDS ufds(n);
  vector<tuple<ll, int, int>> ans;

  sort(all(edges));
  for (auto [a, b, c] : edges) if (ufds.union_set(b, c)) {
    ans.emplace_back(a, b, c);
  }

  return ans;
}

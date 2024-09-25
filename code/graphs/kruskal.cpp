vector<tuple<ll, int, int>> kruskal(int n, vector<tuple<ll, int, int>> &edges) {
  UFDS ufds(n);
  vector<tuple<ll, int, int>> ans;
  sort(edges.begin(), edges.end());
  for (auto [a, b, c] : edges) if (ufds.join(b, c)) {
    ans.emplace_back(a, b, c);
  }
  return ans;
}

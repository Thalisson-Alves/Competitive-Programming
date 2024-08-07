/* Minimum cost edge cover in bipartite graph
 *
 * Given a bipartite graph with n vertices on the left and m vertices on the right, and a set of edges with costs, find the minimum cost edge cover.
 *
 * Parameters:
 * edges: A vector of tuples (u, v, w) representing an edge from vertex u (0, n-1) to vertex v (0, m-1) with cost w.
 * n: The number of vertices on the left.
 * m: The number of vertices on the right.
*/
template <typename T> T edge_cover_min_cost(const vector<tuple<int, int, T>> &edges, int n, int m) {
  vector<T> um(n, numeric_limits<T>::max()), vm(m, numeric_limits<T>::max());
  for (auto [u, v, w] : edges) {
    um[u] = min(um[u], w);
    vm[v] = min(vm[v], w);
  }
  T inf = 0;
  for (auto [u, v, w] : edges)
    inf = min(inf, w-um[u]-vm[v]);
  inf = -inf;

  MinCostFlow<T> mcf(n+m+2);
  int s = n+m, t = s+1;
  for (int i = 0; i < n; i++)
    mcf.add_edge(s, i, 1, 0);
  for (int i = 0; i < m; i++)
    mcf.add_edge(i+n, t, 1, 0);
  for (auto [u, v, w] : edges)
    if (w < um[u]+vm[v])
      mcf.add_edge(u, v+n, 1, w-um[u]-vm[v]+inf);
  mcf.add_edge(s, t, min(n, m), inf);
  auto [flow, cost] = mcf.flow(s, t, min(n, m));

  T base = 0;
  for (int i = 0; i < n; i++) base += um[i];
  for (int i = 0; i < m; i++) base += vm[i];
  return base + cost - inf * flow;
}

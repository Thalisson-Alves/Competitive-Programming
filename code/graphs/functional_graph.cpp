struct FunctionalGraph {
  int cur_id;
  vector<int> par;
  vector<int> pos, pos_inv;
  vector<int> depth;
  vector<int> head;

  FunctionalGraph(int n) : cur_id(0), par(n), pos(n, -1), pos_inv(n, -1), depth(n), head(n) { }

  FunctionalGraph(const vector<int> &p) : FunctionalGraph((int)p.size()) {
    copy(p.begin(), p.end(), par.begin());
    build();
  }

  // Assumes `u` is in a cycle, O(1)
  int cycle_size(int u) const {
    assert(depth[u] == 0);
    return pos[cycle_end(u)] - pos[cycle_begin(u)] + 1;
  }
  // Assumes `u` is in a cycle, O(1)
  int cycle_begin(int u) const {
    assert(depth[u] == 0);
    return par[head[u]];
  }
  // Assumes `u` is in a cycle, O(1)
  int cycle_end(int u) const {
    assert(depth[u] == 0);
    return head[u];
  }
  // Assumes `u` is in a cycle, O(1)
  int cycle_relative_pos(int u) const {
    assert(depth[u] == 0);
    return pos[u] - pos[cycle_begin(u)];
  }

  // k-th ancestor, O(log V)
  int kth_parent(int u, ll k) const {
    while (depth[u]) {
      int h = head[u], len = depth[u] - depth[h];
      if (len >= k)
        return pos_inv[pos[u] - k];
      k -= len + 1, u = par[h];
    }

    int start = cycle_begin(u);
    int relative_pos = cycle_relative_pos(u);
    return pos_inv[pos[start] + (relative_pos + k) % cycle_size(u)];
  }

  // Distance to root, O(log V)
  // {root vertex, number of moves}
  pair<int, int> dist_to_root(int u) const {
    int dist = 0;
    while (depth[u]) {
      int h = head[u], len = depth[u] - depth[h];
      dist += len + 1, u = par[h];
    }
    return {u, dist};
  }

  // Distance until repeat, O(log V)
  // {root vertex, number of moves}
  pair<int, int> dist_to_repeat(int u) const {
    auto [root, dist] = dist_to_root(u);
    return {root, dist + cycle_size(root)};
  }

  // Distance to reach `v` from `u`, O(log V)
  int reach(int u, int v) const {
    if (depth[u] < depth[v]) return -1;
    int dist = depth[u] - depth[v];
    u = kth_parent(u, dist);

    if (u == v) return dist;

    if (depth[u] or head[u] != head[v]) return -1;

    // only go forward
    if (pos[u] <= pos[v]) return dist + pos[v] - pos[u];

    // do cycle
    return dist + cycle_relative_pos(v) + pos[cycle_end(u)] - pos[u] + 1;
  }

  // data[i] = value of vertex i
  template <class T> vector<T> segtree_rearrange(const vector<T> &data) const {
    assert(data.size() == size(par));
    vector<T> ret;
    ret.reserve(size(par));
    for (int i = 0; i < (int)size(par); i++)
      ret.emplace_back(data[pos_inv[i]]);
    return ret;
  }

  // Query for vertices on path [u, v] (INCLUSIVE)
  // If u and v are not LCA of each other, returns immediately
  bool for_each_vertex(int u, int v, const auto &f) const {
    static_assert(std::is_invocable_r_v<void, decltype(f), int, int>);

    auto path = vertex_path(u, v);
    if (path.empty()) return false;
    for (auto [l, r] : path) f(l, r);
    return true;
  }

  // Reach first vertex in cycle, O(log V)
  // Returns the first vertex in cycle
  int for_each_vertex_to_root(int u, const auto &f) const {
    static_assert(std::is_invocable_r_v<void, decltype(f), int, int>);

    int last = u;
    while (depth[u]) {
      int v = head[u];
      if (pos[u] > pos[v]) swap(u, v);
      f(pos[u], pos[v]);
      u = par[head[u]];
      last = u;
    }

    return last;
  }

  // Reach first repeating vertex, O(log V)
  // Returns the first repeating vertex
  int for_each_vertex_to_repeat(int u, const auto &f) const {
    static_assert(std::is_invocable_r_v<void, decltype(f), int, int>);

    int last = for_each_vertex_to_root(u, f);
    if (last != cycle_end(last))
      f(pos[par[last]], pos[cycle_end(last)]);
    f(pos[cycle_begin(last)], pos[last]);
    return last;
  }

  // Path ranges from `u` to `v` [INCLUSIVE], O(log V)
  vector<pair<int, int>> vertex_path(int u, int v) const {
    vector<pair<int, int>> path;
    if (depth[u] < depth[v]) return {};

    int k = depth[u] - depth[v];
    while (depth[u]) {
      int h = head[u], len = depth[u] - depth[h];
      if (len >= k) {
        path.emplace_back(pos[pos_inv[pos[u] - k]], pos[u]);
        u = pos_inv[pos[u] - k];
        break;
      }
      path.emplace_back(pos[h], pos[u]);
      k -= len + 1, u = par[h];
    }

    if (u == v) {
      if (!depth[u])
        path.emplace_back(pos[v], pos[v]);
      return path;
    }

    if (depth[u] or head[u] != head[v]) return {};

    if (pos[u] <= pos[v]) {
      path.emplace_back(pos[u], pos[v]);
      return path;
    }

    path.emplace_back(pos[u], pos[cycle_end(u)]);
    path.emplace_back(pos[cycle_begin(u)], pos[v]);
    return path;
  }

private:
  void build() {
    vector<vector<int>> g(par.size());
    for (int i = 0; i < (int)par.size(); i++)
      g[par[i]].push_back(i);

    vector<int> subtree_sz(par.size()), heavy_child(par.size());
    stack<pair<int, int>> dfs_st;
    queue<int> bfs_q;
    auto dfs_build = [&]() {
      while (not dfs_st.empty()) {
        auto &[u, c] = dfs_st.top();
        if (c < (int)g[u].size()) {
          int nxt = g[u][c++];
          if (nxt == par[u] or pos[nxt] != -1) continue;
          depth[nxt] = depth[u] + 1;
          dfs_st.emplace(nxt, 0);
        } else {
          dfs_st.pop();
          int max_subtree_sz = 0;
          subtree_sz[u] = 1;
          heavy_child[u] = -1;
          for (auto nxt : g[u]) if (nxt != par[u] and pos[nxt] == -1) {
            subtree_sz[u] += subtree_sz[nxt];
            if (subtree_sz[nxt] > max_subtree_sz)
              max_subtree_sz = subtree_sz[nxt], heavy_child[u] = nxt;
          }
        }
      }
    };
    auto bfs_build = [&]() {
      while (not bfs_q.empty()) {
        auto h = bfs_q.front();
        bfs_q.pop();
        if (pos[h] != -1) {
          for (auto nxt : g[h]) if (pos[nxt] == -1) {
            bfs_q.push(nxt);
          }
          continue;
        }

        for (int u = h; u != -1; u = heavy_child[u]) {
          pos[u] = cur_id++;
          pos_inv[pos[u]] = u;
          head[u] = h;
          for (auto nxt : g[u])
            if (par[u] != nxt and nxt != heavy_child[u] and pos[nxt] == -1)
              bfs_q.push(nxt);
        }
      }
    };

    for (int i = 0; i < (int)par.size(); i++) if (pos[i] == -1) {
      auto cycle = _cycle_start(i);
      int c = cycle;
      do {
        c = par[c];
        pos[c] = cur_id++;
        pos_inv[pos[c]] = c;
        head[c] = cycle;
        dfs_st.emplace(c, 0);
        bfs_q.push(c);
      } while (c != cycle);

      dfs_build();
      bfs_build();
    }
  }

  int _cycle_start(int i) {
    int tortoise = i, hare = i;
    do {
      tortoise = par[tortoise];
      hare = par[par[hare]];
    } while (tortoise != hare);
    tortoise = i;
    while (tortoise != hare) {
      tortoise = par[tortoise];
      hare = par[hare];
    }

    return hare;
  }
};

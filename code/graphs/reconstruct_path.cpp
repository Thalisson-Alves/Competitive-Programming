template <typename Node> vector<Node> reconstruct_path(Node t, const vector<Node> &prev, Node default_node = -1) {
  vector<Node> path;
  if (prev[t] == -1)
    return {};

  for (; t != default_node; t = prev[t])
    path.push_back(t);
  reverse(path.begin(), path.end());
  return path;
}

struct BinaryLifting
{
  vector<int> far, level, parent;

  BinaryLifting(vector<int> &ps) : far(ps.size(), -1), level(ps.size()), parent(ps)
  {
    level[0] = 1;
    for (int i = 1; i < (int)parent.size(); i++)
    {
      level[i] = level[parent[i]] + 1;

      int p1 = parent[i];
      int p2 = far[p1];

      if (p2 > -1 and far[p2] > -1 and level[p1] - level[p2] == level[p2] - level[far[p2]])
        far[i] = far[p2];
      else
        far[i] = p1;
    }
  }

  int query(int node, int k) const
  {
    while (node >= 0 and k > 0)
    {
      if (far[node] > -1 and level[node] - k <= level[far[node]])
      {
        k -= level[node] - level[far[node]];
        node = far[node];
      }
      else
      {
        k--;
        node = parent[node];
      }
    }

    return node;
  }
};

/* Tree Minimum Inversion Permutation
 *
 * Given a tree in the form of a parent sequence ps,
 * returns a permutation q such that order[ps[i]] < order[i] for all i
 * and minimizes \sum_{i=0,1,...,n-1}(v[q[i]].first * \sum_{j=0,1,...,i}v[q[j]].second)
 *
 * The tree is represented by a parent sequence ps, where ps[i] = -1 if i is the root
 *
 * Complexity: O(n log n)
 */
vector<int> min_inversion_permutation(const vector<int> &ps, const vector<pair<int, int>> &v) {
  using T = tuple<ll, ll, int>;
  constexpr auto comp = [](const T &a, const T &b) {
    return get<0>(a)*get<1>(b) < get<0>(b)*get<1>(a);
  };
  priority_queue<T, vector<T>, decltype(comp)> pq(comp);
  int root = -1;
  vector<int> f(size(ps), -1), first(size(ps)), last(size(ps));
  vector<pair<ll, ll>> val(size(ps));
  for (int i = 0; i < (int)size(ps); i++) {
    if (~ps[i]) pq.emplace(v[i].first, v[i].second, i);
    else root = i;
    first[i] = last[i] = i;
    val[i] = v[i];
  }
  UFDS ufds((int)size(ps));
  while (size(pq)) {
    auto [zeros, ones, i] = pq.top();
    pq.pop();
    int p = ufds.find(ps[i]);
    i = ufds.find(i);
    if (!ufds.join(i, p)) continue;
    int x = ufds.find(i);
    f[last[p]] = first[i];
    first[x] = first[p];
    last[x] = last[i];
    val[x] = {val[i].first + val[p].first, val[i].second + val[p].second};
    if (~ps[first[x]]) pq.emplace(val[x].first, val[x].second, first[x]);
  }
  vector<int> res;
  for (; ~root; root = f[root]) res.push_back(root);
  return res;
}

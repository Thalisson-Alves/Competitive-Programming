/* Given a permutation p and an integer k
 * Find the permutation after applying the following operation k times:
 * - For i = 0..n-1, simultaneously update p[i] = p[p[i]]
 *
 * Time complexity: O(n + m * log(k)), where m is the number of cycles in the permutation
 */
ll fpow(ll x, ll p, ll mod) {
  ll res = 1;
  while (p) {
    if (p & 1) res = res * x % mod;
    p >>= 1;
    x = x * x % mod;
  }
  return res;
}
vector<int> permute_permutation(const vector<int> &p, ll k) {
  vector<bool> vis(p.size());
  vector<int> res(p.size());
  for (int i = 0; i < (int)p.size(); i++) if (!vis[i]) {
    vector<int> c;
    for (int u = i; !vis[u]; vis[u] = 1, c.push_back(u), u = p[u]);
    int shift = (int)fpow(2, k, c.size());
    for (int j = 0; j < (int)c.size(); j++)
      res[c[j]] = c[(j+shift)%c.size()];
  }
  return res;
}

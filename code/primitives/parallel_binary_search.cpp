/* Parallel Binary Search
 *
 * Given a set of intervals [l[i], r[i]], for each interval we want to find the smallest value `x` such that `l[i] <= x <= r[i]` and `check(x)` is true.
 * We do this by simulating some actions and updating all intervals that should be updated.
 *
 * NOTE:
 * - l[i] <= r[i]
 * - If l[i] != r[i] then l[i] >= 0
 *
 * Arguments:
 * - n: the number of actions to simulate
 * - inter: the intervals
 * - init: a function that initializes the state
 * - apply: a function that simulates the `i`-th action
 * - check: a function that checks if the value `x` is valid for the `i`-th interval
 *
 * Complexity: O((n * O(apply) + |inter| * O(check)) * log(max(r[i] - l[i])))
*/

void parallel_binary_search(int n, vector<pair<int, int>> &inter, auto init, auto apply, auto check) {
  static_assert(std::is_invocable_r_v<void, decltype(init)>);
  static_assert(std::is_invocable_r_v<void, decltype(apply), int>);
  static_assert(std::is_invocable_r_v<bool, decltype(check), int>);

  vector<vector<int>> mids([&inter](){
    int mx = -1;
    for (auto [l, r] : inter) {
      assert(l <= r and (l >= 0 or l == r));
      mx = max(mx, r);
    }
    return mx;
  }());
  for (int i = 0; i < (int)inter.size(); i++) {
    if (inter[i].first != inter[i].second)
      mids[midpoint(inter[i].first, inter[i].second)].push_back(i);
  }

  for (bool changed = 1; changed;) {
    changed = 0;
    init();
    for (int i = 0; i < n; i++) {
      apply(i);
      while (!mids[i].empty()) {
        changed = 1;
        auto cur = mids[i].back();
        mids[i].pop_back();
        if (check(cur)) inter[cur].second = i;
        else inter[cur].first = i + 1;
        if (inter[cur].first < inter[cur].second)
          mids[midpoint(inter[cur].first, inter[cur].second)].push_back(cur);
      }
    }
  }
}

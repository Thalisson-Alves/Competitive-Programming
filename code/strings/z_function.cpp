template <typename T> vector<int> z_function(const T &s) {
  vector<int> z(s.size());
  for(int i = 1, l = 0, r = 0; i < (int)s.size(); i++) {
    if (i < r) z[i] = min(r - i, z[i - l]);
    for (; i + z[i] < (int)s.size() && s[z[i]] == s[i + z[i]]; z[i]++);
    if (i + z[i] > r) l = i, r = i + z[i];
  }
  return z;
}

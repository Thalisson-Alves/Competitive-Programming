vector<int> kmp(const string &p) {
  int m = (int)p.size(), t = -1;
  vector<int> bs(m + 1, -1);

  for (int i = 1; i <= m; i++) {
    for (; t > -1 and p[t] != p[i - 1]; t = bs[t]);
    ++t;
    bs[i] = (i == m or p[t] != p[i]) ? t : bs[t];
  }

  return bs;
}

int count_occurences(const string &s, const string &p) {
  int n = (int)s.size(), m = (int)p.size(), i = 0, j = 0, occ = 0;
  auto bs = kmp(p);

  while (i <= n - m) {
    for (; j < m and p[j] == s[i + j]; ++j);
    if (j == m) ++occ;

    int shift = j - bs[j];
    i += shift;
    j = max(0, j - shift);
  }

  return occ;
}

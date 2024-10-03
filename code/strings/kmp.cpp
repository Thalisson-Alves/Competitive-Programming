vector<int> kmp(const string &s) {
  vector<int> pi(size(s));
  for (int i = 1; i < (int)size(s); i++) {
    int j = pi[i-1];
    for (; j and s[i]!=s[j]; j=pi[j-1]);
    pi[i] = j+(s[i]==s[j]);
  }
  return pi;
}
int count_occurences(const string &s, const string &p) {
  int m = (int)p.size(), occ = 0;
  auto pi = kmp(p);
  for (int i = 0, j = 0; i < (int)size(s); i++) {
    for (; j and (j==m or s[i]!=p[j]); j=pi[j-1]);
    if (s[i] == p[j]) occ += ++j == m;
  }
  return occ;
}

struct Mex {
  vector<int> hist; set<int> missing;
  Mex(int n) : hist(n) { for (int i = 0; i <= n; i++) missing.insert(i); }
  int operator()() const { return *begin(missing); }
  void add(int x) { if (x < (int)size(hist) and !hist[x]++) missing.erase(x); }
  void remove(int x) { if (x < (int)size(hist) and hist[x] and !--hist[x]) missing.insert(x); }
};

template <typename T=mint> T factorial(int n) {
  static vector<T> fact{1};
  while ((int)size(fact) <= n) fact.push_back(fact.back() * size(fact));
  return fact[n];
}
template <typename T=mint> T comb(int n, int k) {
  if (n < k) return 0;
  return factorial<T>(n) / (factorial<T>(n-k) * factorial<T>(k));
}
// same as comb(2*n, n) / (n + 1)
template <typename T=mint> T catalan(int n) {
  return factorial<T>(2*n) / (factorial<T>(n) * factorial<T>(n + 1));
}

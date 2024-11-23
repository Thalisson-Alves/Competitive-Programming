template <typename T=mint> T factorial(int n) {
  static vector<T> fact{1, 1};
  while ((int)size(fact) <= n) fact.push_back(fact.back() * size(fact));
  return fact[n];
}
template <typename T=mint> T factorial_inv(int n) {
  static vector<T> inv{1, 1}, finv{1, 1};
  while ((int)size(inv) <= n) {
    inv.push_back(T::mod - T::mod / size(inv) * inv[T::mod % size(inv)].value() % T::mod);
    finv.push_back(finv.back() * inv.back());
  }
  return finv[n];
}
template <typename T=mint> T comb(int n, int k) {
  if (n < k) return 0;
  return factorial<T>(n) * factorial_inv<T>(n-k) * factorial_inv<T>(k);
}
// same as comb(2*n, n) / (n + 1)
template <typename T=mint> T catalan(int n) {
  return factorial<T>(2*n) * factorial_inv<T>(n) * factorial_inv<T>(n + 1);
}

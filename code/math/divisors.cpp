template <typename T> vector<T> divisors(T n) {
  vector<T> d;
  for (T i = 1; (ll)i*i <= n; i++) if (n%i == 0) {
    d.push_back(i);
    if (n/i != i) d.push_back(n/i);
  }
  return d;
}

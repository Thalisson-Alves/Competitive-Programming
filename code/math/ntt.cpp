template <uint_fast64_t Modulus>
constexpr typename modint<Modulus>::u64 modint<Modulus>::mod;
using mint = modint<1000000007>;

template<int m> constexpr int primitive_root() {
  if constexpr (m == 1224736769) return 3;
  else if constexpr (m == 1053818881) return 7;
  else if constexpr (m == 1051721729) return 6;
  else if constexpr (m == 1045430273) return 3;
  else if constexpr (m == 1012924417) return 5;
  else if constexpr (m == 1007681537) return 3;
  else if constexpr (m == 1004535809) return 3;
  else if constexpr (m ==  998244353) return 3;
  else if constexpr (m ==  985661441) return 3;
  else if constexpr (m ==  976224257) return 3;
  else if constexpr (m ==  975175681) return 17;
  else if constexpr (m ==  962592769) return 7;
  else if constexpr (m ==  950009857) return 7;
  else if constexpr (m ==  943718401) return 7;
  else if constexpr (m ==  935329793) return 3;
  else if constexpr (m ==  924844033) return 5;
  else if constexpr (m ==  469762049) return 3;
  else if constexpr (m ==  167772161) return 3;
  else if constexpr (m == 2) return 1;
  else return -1;
}

template <typename Mint> void ntt(vector<Mint> &a, bool invert=false) {
  int n = (int)a.size(), s = __builtin_ctz(n);
  assert(n == (1 << s));

  constexpr auto g = Mint(primitive_root<Mint::mod>());
  static array<vector<Mint>, 2> roots;
  while ((int)roots[0].size() <= s) {
    roots[0].push_back(g.pow((Mint::mod-1) / (1 << roots[0].size())));
    roots[1].push_back(roots[0].back().inv());
  }
  
  const auto &rs = roots[invert];
  vector<Mint> b(n);
  for (int i = 1; i <= s; i++) {
    int w = n >> i;
    Mint base = rs[i], now = 1;
    for (int y = 0; y < n / 2; y += w) {
       for (int x = 0; x < w; x++) {
         auto l = a[y << 1 | x];
         auto r = now * a[y << 1 | x | w];
         b[y | x] = l + r;
         b[y | x | n >> 1] = l - r;
       }
       now *= base;
    }
    swap(a, b);
  }

  if (invert) {
    auto inv = Mint(n).inv();
    for (auto &x : a) x *= inv;
  }
}

template <int m = mint::mod, typename T, enable_if_t<primitive_root<m>() != -1, bool> = true>
vector<modint<m>> convolution(const vector<T> &a, const vector<T> &b) {
  using Mint = modint<m>;
  vector<Mint> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  const int N = (int)(a.size() + b.size() - 1);
  int n = 1;
  while (n < N) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  ntt<Mint>(fa, false);
  ntt<Mint>(fb, false);
  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  ntt<Mint>(fa, true);
  fa.resize(N);
  return fa;
}

template <int m, typename Mint1, typename Mint2, typename Mint3>
modint<m> garner_algorithm(Mint1 a1, Mint2 a2, Mint3 a3) {
  using Mint = modint<m>;
  static constexpr auto r12 = Mint2(Mint1::mod).inv();
  static constexpr auto r13 = Mint3(Mint1::mod).inv();
  static constexpr auto r23 = Mint3(Mint2::mod).inv();
  a2 = (a2 - a1.value()) * r12;
  a3 = (a3 - a1.value()) * r13;
  a3 = (a3 - a2.value()) * r23;
  return Mint(a1.value()) + Mint(Mint1::mod) * a2.value() + (Mint(Mint1::mod) * Mint(Mint2::mod)) * a3.value();
}

template <int m = mint::mod, typename T, enable_if_t<primitive_root<m>() == -1, bool> = true>
vector<modint<m>> convolution(const vector<T> &a, const vector<T> &b) {
  using Mint = modint<m>;
  vector<Mint> c(a.size() + b.size() - 1);
  if (a.size() <= 32 or b.size() <= 32) {
    for (int i = 0; i < (int)a.size(); i++)
      for (int j = 0; j < (int)b.size(); j++)
        c[i+j] += a[i] * b[j];
    return c;
  }

  constexpr int PRIMES[3] = {1004535809, 998244353, 985661441};
  #define vp(_p) vector<modint<PRIMES[_p]>>
  vp(0) z0 = convolution<PRIMES[0]>(vp(0)(all(a)), vp(0)(all(b)));
  vp(1) z1 = convolution<PRIMES[1]>(vp(1)(all(a)), vp(1)(all(b)));
  vp(2) z2 = convolution<PRIMES[2]>(vp(2)(all(a)), vp(2)(all(b)));

  for (int i = 0; i < (int)c.size(); i++) {
    c[i] = garner_algorithm<m>(z0[i], z1[i], z2[i]);
  }
  return c;
}

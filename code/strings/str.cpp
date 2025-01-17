namespace str {
  constexpr string_view digits() { return "0123456789"; }
  constexpr string_view lower() { return "abcdefghijklmnopqrstuvwxyz"; }
  constexpr string_view upper() { return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; }
  template <typename T> string join(const T &values, const string_view &sep=" ") {
    if (values.empty()) return {};
    stringstream ss;
    auto it = values.begin();
    ss << *it;
    for (++it; it != values.end(); ++it) ss << sep << *it;
    return ss.str();
  }
  template <typename T> inline T cast(const string &s) {
    stringstream ss(s);
    T res;
    ss >> res;
    return res;
  }
  void split_for_each(const string &s, const string_view &sep, auto f) {
    static_assert(is_invocable_r_v<void, decltype(f), string>);
    size_t pos = 0, last = 0;
    while ((pos = s.find(sep, last)) != string::npos) {
      if (pos > last)
        f(s.substr(last, pos - last));
      last = pos + sep.size();
    }
    if (last < s.size())
      f(s.substr(last));
  }
  template<typename T> void split_for_each(const string &s, const string_view &sep, auto f) {
    static_assert(is_invocable_r_v<void, decltype(f), T>);
    if constexpr (is_same_v<T, string>) {
      split_for_each(s, sep, f);
      return;
    }
    split_for_each(s, sep, [&](const string &x) { f(cast<T>(x)); });
  }
  template <typename Out> void split_into(const string &s, const string_view &sep, Out out) {
    using T = typename Out::container_type::value_type;
    split_for_each<T>(s, sep, [&](const T &x) { *out++ = x; });
  }
  vector<string> split(const string &s, const string_view &sep=" ") {
    vector<string> res;
    split_for_each(s, sep, [&](const string &x) { res.push_back(x); });
    return res;
  }
  template <size_t N, typename T=string> auto split(const string &s, const string_view &sep=" ") {
    array<T, N> res;
    auto it = res.begin();
    split_for_each<T>(s, sep, [&](const T &x) { *it++ = x; });
    return res;
  }
  template <typename T> vector<T> split(const string &s, const string_view &sep=" ") {
    vector<T> res;
    split_for_each<T>(s, sep, [&](const T &x) { res.emplace_back(x); });
    return res;
  }
  void replace_all(string &s, const string_view &from, const string_view &to) {
    if (from.empty()) return;
    size_t pos = 0;
    while ((pos = s.find(from, pos)) != string::npos) {
      s.replace(pos, from.size(), to);
      pos += to.size();
    }
  }
  string replace_copy(string s, const string_view &from, const string_view &to) {
    replace_all(s, from, to);
    return s;
  }
};

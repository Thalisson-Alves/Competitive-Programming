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
  vector<string> split(const string &s, const string_view &sep=" ") {
    vector<string> res;
    split_for_each(s, sep, [&](const string &x) { res.push_back(x); });
    return res;
  }
  template <typename T> vector<T> split(const string &s, const string_view &sep=" ") {
    vector<T> res;
    split_for_each(s, sep, [&](const string &x) {
      stringstream ss(x);
      T val;
      ss >> val;
      res.emplace_back(val);
    });
    return res;
  }
  template <typename Out> void split_into(const string &s, const string_view &sep, Out out) {
    using T = typename Out::container_type::value_type;
    split_for_each(s, sep, [&](const string &x) {
      stringstream ss(x);
      T val;
      ss >> val;
      *out++ = val;
    });
  }
};

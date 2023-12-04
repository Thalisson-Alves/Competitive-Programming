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

  vector<string> split(const string &s, const string_view &sep=" ") {
    vector<string> res;
    size_t pos = 0, last = 0;
    while ((pos = s.find(sep, last)) != string::npos) {
      if (pos > last)
        res.push_back(s.substr(last, pos - last));
      last = pos + sep.size();
    }
    res.push_back(s.substr(last));
    return res;
  }
  template <typename T> vector<T> split(const string &s, const string_view &sep=" ") {
    vector<T> res;
    for (const auto &x : split(s, sep)) {
      stringstream ss(x);
      T val;
      ss >> val;
      res.emplace_back(val);
    }
    return res;
  }
  template <typename T> void split_into(const string &s, const string_view &sep, T out) {
    stringstream ss(s);
    string token;
    while (getline(ss, token, sep[0])) {
      stringstream ss2(token);
      typename T::container_type::value_type val;
      ss2 >> val;
      *out++ = val;
    }
  }
};

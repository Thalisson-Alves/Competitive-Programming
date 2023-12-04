namespace str {
  constexpr string_view digits() { return "0123456789"; }
  constexpr string_view lower() { return "abcdefghijklmnopqrstuvwxyz"; }
  constexpr string_view upper() { return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; }
  template <typename T> inline string join(const T &values, const string_view &sep="") {
    if (values.empty()) return {};
    auto it = values.begin();
    string res = *it;
    while (++it != values.end()) {
      res += sep;
      res += *it;
    }
    return res;
  }
  template <typename T> inline string join(const T &values, const char sep) {
    return join(values, string_view(&sep, 1));
  }
  template <typename T> inline string join(const T &values, const char *sep) {
    return join(values, string_view(sep));
  }

  inline vector<string> split(const string &s, const string_view &sep=" ") {
    vector<string> res;
    size_t pos = 0, last = 0;
    while ((pos = s.find(sep, last)) != string::npos) {
      res.push_back(s.substr(last, pos - last));
      last = pos + sep.size();
    }
    res.push_back(s.substr(last));
    return res;
  }
  inline vector<string> split(const string &s, const char sep) {
    return split(s, string_view(&sep, 1));
  }
  inline vector<string> split(const string &s, const char *sep) {
    return split(s, string_view(sep));
  }
  template <typename T> inline vector<T> split(const string &s, const string_view &sep=" ") {
    vector<T> res;
    for (const auto &x : split(s, sep)) {
      stringstream ss(x);
      T val;
      ss >> val;
      res.emplace_back(val);
    }
    return res;
  }
};

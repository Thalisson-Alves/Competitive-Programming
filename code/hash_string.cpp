template <int p1=31, int q1=1000000007, int p2=29, int q2=1000000009>
struct HashString {
  vector<pair<int, int>> suf, powers;

  HashString(const string &s) : suf(s.size()+1), powers(s.size()+1) {
    powers[0] = {1, 1};
    powers[1] = {p1, p2};

    for (int i = (int)s.size()-1; ~i; --i) {
      suf[i].first = (int)((s[i] + (ll)suf[i+1].first * powers[1].first) % q1);
      suf[i].second = (int)((s[i] + (ll)suf[i+1].second * powers[1].second) % q2);
    }
    for (int i = 2; i <= (int)s.size(); i++) {
      powers[i].first = (int)((ll)powers[i-1].first * powers[1].first % q1);
      powers[i].second = (int)((ll)powers[i-1].second * powers[1].second % q2);
    }
  }

  bool operator<(const HashString &a) const {
    return hash() < a.hash();
  }

  pair<int, int> substr(int l) const {
    return substr(l, size()-1);
  }

  pair<int, int> substr(int l, int r) const {
    assert(0 <= l and l <= r and r < (int)suf.size() - 1);
    int a = (int)((((suf[l].first - (ll)suf[r+1].first * powers[r-l+1].first) % q1) + q1) % q1);
    int b = (int)((((suf[l].second - (ll)suf[r+1].second * powers[r-l+1].second) % q2) + q2) % q2);
    return {a, b};
  }

  int max_prefix(const HashString &h) const {
    int l = 0, r = (int)min(size(),h.size())-1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (substr(0, mid) == h.substr(0, mid)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return l;
  }

  int max_suffix(const HashString &h) const {
    int l = 1, r = (int)min(size(),h.size());
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (substr(size()-mid) == h.substr(h.size()-mid)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return r;
  }

  pair<int, int> hash() const { return suf[0]; }

  int size() const { return (int)suf.size() - 1; }
};

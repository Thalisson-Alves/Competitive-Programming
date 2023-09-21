template<typename T> vector<T> split(const string &s)
{
  vector<T> ans;
  stringstream ss(s);
  for (T x; ss >> x; ans.push_back(x));
  return ans;
}

#include <bits/stdc++.h>
using namespace std;

int edit_distance(const string &s, const string &t)
{
  const auto c_i = 1, c_r = 1, c_u = 1;
  vector<int> prev(max(s.size(), t.size()) + 1), line(prev.size());

  for (int i = 1; i <= (int)t.size(); i++)
    prev[i] = i*c_i;

  for (int i = 1; i <= (int)s.size(); i++)
  {
    line[0] = i * c_r;
    for (int j = 1; j <= (int)t.size(); j++)
      line[j] = min({prev[j-1] + c_u * (s[i-1] != t[j-1]), line[j-1] + c_i, prev[j] + c_r});
    swap(prev, line);
  }
  return prev[t.size()];
}

void solve()
{
  string a, b;
  cin >> a >> b;
  cout << edit_distance(a, b) << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++)
    solve();

  return 0;
}

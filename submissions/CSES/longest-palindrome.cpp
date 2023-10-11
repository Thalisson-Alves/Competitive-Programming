#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...) 4269
#endif

#define all(x) x.begin(), x.end()
 
using ll = long long;
using ull = unsigned long long;
 
const vector<pair<int, int>> dir4{{1,0},{-1,0},{0,1},{0,-1}};
const vector<pair<int, int>> dir8{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

string longest_palindrome(const string &s)
{
  int n = (int)s.size();
  vector<array<int, 2>> dp(n);

  pair<int, int> odd(0, -1), even(0, -1);
  pair<int, int> ans;
  for (int i = 0; i < n; i++)
  {
    int k = 0;
    if (i > odd.second) k = 1;
    else k = min(dp[odd.first+odd.second-i][0], odd.second-i+1);
    while (i - k >= 0 and i + k < n and s[i-k] == s[i+k]) k++;
    dp[i][0] = k--;
    if (i + k > odd.second) odd = {i - k, i + k};
    if (2 * dp[i][0] - 1 > ans.second) ans = {i - k, 2 * dp[i][0] - 1};

    k = 0;
    if (i <= even.second) k = min(dp[even.first + even.second - i + 1][1], even.second - i + 1);
    while (i - k - 1 >= 0 and i + k < n and s[i-k-1] == s[i+k]) k++;
    dp[i][1] = k--;
    if (i+k > even.second) even = {i-k-1, i+k};
    if (2*dp[i][1] > ans.second) ans = {i-k-1, 2*dp[i][1]};
  }
  return s.substr(ans.first, ans.second);
}

void solve()
{
  string s;
  cin >> s;
  cout << longest_palindrome(s) << '\n';
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
 

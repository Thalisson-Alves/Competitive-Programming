/* Returns the lexicographically smallest cyclic shift of a string.
 *
 * The cyclic shift of a string is a string that can be obtained by moving the
 * first few characters of the string to the end.
 * Example, the cyclic shifts of "abc" are "abc", "bca", and "cab".
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
*/
string min_cyclic_string(string &s) {
  s += s;
  int n = (int)size(s);
  int i = 0, res = 0;
  while (i < n / 2) {
    res = i;
    int j = i + 1, k = i;
    while (j < n && s[k] <= s[j]) {
      if (s[k] < s[j]) k = i;
      else k++;
      j++;
    }
    while (i <= k) i += j - k;
  }
  auto mn = s.substr(res, n / 2);
  s.resize(n / 2);
  return mn;
}

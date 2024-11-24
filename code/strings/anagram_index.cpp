/* Count the number of anagrams of s that are lexicographically smaller than t
 *
 * Time complexity: O(|s|)
 */
ll count_anagrams_less_than(const string &s, const string &t) {
  array<int, 26> cnt;
  cnt.fill(0);
  for (auto c : t) cnt[c-'a']++;
  mint res = 0, dem = 1;
  for (auto x : cnt) dem *= factorial_inv(x);
  for (int i = 0; i < (int)t.size(); i++) {
    mint tot = factorial((int)t.size()-i-1);
    for (int j = 0; j < s[i]-'a'; j++) if (cnt[j])
      res += tot * dem * factorial(cnt[j]) * factorial_inv(cnt[j]-1);
    if (!cnt[s[i]-'a']) break;
    dem *= factorial(cnt[s[i]-'a']--);
    dem *= factorial_inv(cnt[s[i]-'a']);
  }
  return res.value();
}
ll anagram_index(const string &s) {
  return count_anagrams_less_than(s, s);
}

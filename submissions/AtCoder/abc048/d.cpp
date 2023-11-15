#include <bits/stdc++.h>
using namespace std;
// #define ll long long
// #define debug(x) cerr << #x << ": " << x << '\n'
// g++.exe -Wall -Wextra -Wpedantic -std=c++11 -o comp comp.cpp

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	cout << ((s.front() == s.back() && s.size() % 2) || (s.front() != s.back() && !(s.size() % 2)) ? "Second" : "First") << '\n';

	return 0;
}

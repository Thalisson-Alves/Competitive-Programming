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
	int ans = 0;
	char current = s[0];
	for (char c : s) {
		if (c != current)
			ans++, current = c;
	}

	cout << ans << '\n';

	return 0;
}

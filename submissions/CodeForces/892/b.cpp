#include <bits/stdc++.h>
using namespace std;
// #define ll long long
// #define debug(x) cerr << #x << ": " << x << '\n'
// g++.exe -Wall -Wextra -Wpedantic -std=c++11 -o comp comp.cpp

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> ns(n);
	for (auto &x : ns) cin >> x;
	int ans{0}, next_alive{n-1};
	for (int i = n-1; i >= 0; i--) {
		if (i == next_alive) ans++, next_alive = i - ns[i] - 1;
		if (i - ns[i] <= next_alive)
			next_alive = i - ns[i] - 1;
	}

	cout << ans << '\n';

	return 0;
}

#include <bits/stdc++.h>
using namespace std;
// #define ll long long
// #define debug(x) cerr << #x << ": " << x << '\n'
// g++.exe -Wall -Wextra -Wpedantic -std=c++11 -o comp comp.cpp

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, b;
	cin >> n >> b;
	vector<long long> a(n);
	for (auto& x : a) cin >> x;
	long long ans = 0ll;

	for (int i = 1; i < n; i++) {
		auto sum = a[i] + a[i-1];
		auto dif = max(0ll, sum - b);

		ans += dif;
		a[i] -= min(dif, a[i]);
	}

	cout << ans << '\n';

	return 0;
}

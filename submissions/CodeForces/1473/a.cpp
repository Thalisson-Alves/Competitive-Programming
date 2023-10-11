#include <bits/stdc++.h>
using namespace std;
// #define ll long long
// #define debug(x) cerr << #x << ": " << x << '\n'
// g++.exe -Wall -Wextra -Wpedantic -std=c++11 -o comp comp.cpp

string solve(vector<int>& vs, int d)
{
	sort(vs.begin(), vs.end());
	return (vs.back() <= d ? "YES" : (vs[0] + vs[1] <= d ? "YES" : "NO"));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		vector<int> vs(n);
		for (auto &x : vs) cin >> x;
		cout << solve(vs, d) << '\n';
	}

	return 0;
}
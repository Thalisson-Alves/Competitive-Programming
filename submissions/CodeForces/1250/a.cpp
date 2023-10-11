#include <bits/stdc++.h>
using namespace std;
// #define ll long long
// #define debug(x) cerr << #x << ": " << x << '\n'
// g++.exe -Wall -Wextra -Wpedantic -std=c++11 -o competition competition.cpp

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (auto &x : a) cin >> x;
	map<int, int> position;
	vector<pair<int, int>> ans(n+1);
	for (int i = 1; i <= n; i++) {
		position[i] = i;
		ans[i] = make_pair(i, i);
	}
	map<int, int> mp = position;
	for (int i = 0; i < m; i++) {
		auto p1 = position.find(a[i]);
		if (p1->second == 1) continue;
		auto i2 = mp.find(p1->second-1);
		auto p2 = position.find(i2->second);

		int tmp = p1->second;
		p1->second = p2->second;
		p2->second = tmp;

		mp[p1->second] = p1->first;
		mp[p2->second] = p2->first;

		ans[p1->first].first = min(ans[p1->first].first, p1->second);
		ans[p2->first].second = max(ans[p2->first].second, p2->second);
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	
	return 0;
}

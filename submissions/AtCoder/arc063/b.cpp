#include <bits/stdc++.h>
using namespace std;
// #define ll long long
// #define debug(x) cerr << #x << ": " << x << '\n'
// g++.exe -Wall -Wextra -Wpedantic -std=c++11 -o comp comp.cpp

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	for (auto& x : a) cin >> x;
	priority_queue<int> pq;
	int best = a.back();
	for (int i = n-2; i>=0; i--) {
		pq.push(best - a[i]);
		best = max(best, a[i]);
	}
	auto m = pq.top();
	int ans = 0;
	while (!pq.empty() && pq.top() == m) {
		ans++;
		pq.pop();
	}

	cout << ans << '\n';

	return 0;
}

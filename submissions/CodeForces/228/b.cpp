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
	vector<vector<int>> t1(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			t1[i][j] = x - '0';
		}
	}
	cin >> n >> m;
	vector<vector<int>> t2(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x;
			cin >> x;
			t2[i][j] = x - '0';
		}
	}

	auto limit = [](int i, int j, int a, int b) -> bool { return i >= 0 && i < a && j >= 0 && j < b; };
	pair<int, int> ans;
	long long mx = 0ll;
	int N = max({t1.size(), t1[0].size(), t2.size(), t2[0].size()});
	for (int x = -N; x <= N; x++) {
		for (int y = -N; y <= N; y++) {
			long long count = 0ll;
			for (int i = 0; i < (int)t1.size(); i++) {
				for (int j = 0; j < (int)t1[i].size(); j++) {
					if (limit(i+x, j+y, n, m))
						count += (t1[i][j] * t2[i+x][j+y]);
				}
			}
			if (count > mx) {
				mx = count;
				ans = make_pair(x, y);
			}
		}
	}
	cout << ans.first << ' ' << ans.second << '\n';
	
	return 0;
}

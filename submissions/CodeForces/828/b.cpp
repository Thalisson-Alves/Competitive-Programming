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
	vector<vector<char>> v(n, vector<char>(m));
	int x1 = m, y1 = n, x2 = -1, y2 = -1;
	int black = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 'W') continue;
			x1 = min(x1, j);
			y1 = min(y1, i);
			x2 = max(x2, j);
			y2 = max(y2, i);
			black++;
		}
	}

	int dx = x2 - x1 + 1;
	int dy = y2 - y1 + 1;
	if (dx > n || dy > m)
		cout << "-1\n";
	else if (dx < 0)
		cout << "1\n";
	else
		cout << max(dx, dy) * max(dx, dy) - black << '\n';
	
	return 0;
}

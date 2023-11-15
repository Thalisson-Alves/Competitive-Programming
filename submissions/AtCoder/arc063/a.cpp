#include <bits/stdc++.h>
using namespace std;
// #define ll long long
// #define debug(x) cerr << #x << ": " << x << '\n'
// g++.exe -Wall -Wextra -Wpedantic -std=c++11 -o comp comp.cpp

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int w, h, n;
	cin >> w >> h >> n;
	pair<pair<int, int>, pair<int, int>> rect{{0, 0}, {w, h}};
	for (int i = 0, x, y, a; i < n; i++) {
		cin >> x >> y >> a;
		switch (a) {
		case 1:
			rect.first.first = max(rect.first.first, x);
			break;
		case 2:
			rect.second.first = min(rect.second.first, x);
			break;
		case 3:
			rect.first.second = max(rect.first.second, y);
			break;
		default:
			rect.second.second = min(rect.second.second, y);
		}
	}

	if (rect.second.first < rect.first.first || rect.second.second < rect.first.second) {
		cout << 0 << '\n';
	} else {
		cout << (rect.second.first - rect.first.first) * (rect.second.second - rect.first.second) << '\n';
	}

	return 0;
}

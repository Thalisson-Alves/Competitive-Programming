#include <bits/stdc++.h>
using namespace std;
// #define ll long long
// #define debug(x) cerr << #x << ": " << x << '\n'
// g++.exe -Wall -Wextra -Wpedantic -std=c++11 -o comp comp.cpp

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	vector<int> vt{a, b, c};
	sort(vt.begin(), vt.end());
	if (vt[0] + vt[1] == vt[2])
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}

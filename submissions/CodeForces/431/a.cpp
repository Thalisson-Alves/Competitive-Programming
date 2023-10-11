#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define debug(x) cerr << #x << " = " << x << endl

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int a[4];
	for (int &x: a)
		cin >> x;
	string s;
	cin >> s;
	long ans = 0l;
	for (char c: s)
		ans += a[c-'1'];
	cout << ans << '\n';
	
	return 0;
}
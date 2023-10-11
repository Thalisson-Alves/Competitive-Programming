#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define debug(x) cerr << #x << " = " << x << endl

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	long long pref[n+1];
	pref[0] = 0;
	for(int i = 0; i < n; i++)
		pref[i+1] = pref[i] + a[i];
	double ans = 0.0;
	for (int i = n; i >= k; i--)
		ans += pref[i] - pref[i-k];
	
	cout << fixed << setprecision(8) << ans / (double) (n - k + 1) << '\n';
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define debug(x) cerr << #x << " = " << x << endl

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n, w;
	cin >> n >> w;
	vector<pair<int, int>> a(n), ans(n);
	for(int i = 0; i < n; i++)
		cin >> a[i].first, a[i].second = i;
	sort(a.rbegin(), a.rend());
	
	for (int i = 0; i < n; i++){
		ans[i].first = (a[i].first + 1) / 2;
		ans[i].second = a[i].second;
		w -= ans[i].first;
	}
	if (w < 0){
		cout << "-1\n";
		return 0;
	}
	for (int i = 0; i < n; i++)
		if (w > a[i].first - ans[i].first){
			w -= a[i].first - ans[i].first;
			ans[i].first = a[i].first;
		}
		else{
			ans[i].first += w;
			break;
		}
	sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b){ return a.second < b.second; });
	
	for (int i = 0; i < n; i++)
		cout << ans[i].first << ( i == n - 1 ? '\n' : ' ');
	
	return 0;
}
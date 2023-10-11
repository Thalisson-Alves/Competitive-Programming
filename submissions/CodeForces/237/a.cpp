#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n;
	cin >> n;
	int ans = 0;
	map<pair<int, int>, int> mp;
	for(int i=0, h, m; i<n; i++)
		cin >> h >> m, mp[{h, m}]++, ans = max(mp[{h, m}], ans);
	cout << ans << endl;
	
	return 0;
}
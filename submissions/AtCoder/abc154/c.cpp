#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	map<int, int> mp;
	string ans = "YES\n";
	for(int i=0, x; i<n; i++)
		cin >> x, (++mp[x] > 1? ans="NO\n": ans=ans);
	cout << ans;
	
	return 0;
}
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
	int mx = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		mp[a]++;
		mx = max(mx, mp[a]);
	}
	if(mx > (n+1)/2)
		cout << "NO\n";
	else
		cout << "YES\n";
	
	return 0;
}
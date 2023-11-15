#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n;
	cin >> n;
	int mn = 1e9+7;
	int ans = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x < mn)
			ans++, mn = x;
	}
	cout << ans << endl;
	
	return 0;
}
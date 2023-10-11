#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	int mx = 0, mn = 1e9+7;
	for(int i = 0; i<n; i++){
		int x;
		cin >> x;
		mx = max(mx, x);
		mn = min(mn, x);
	}
	int _mn = 1e9+7;
	for(int i=0; i<m; i++){
		int x;
		cin >> x;
		_mn = min(_mn, x);
	}
	int ans = (2*mn < _mn && mx < _mn? max(2*mn, mx): -1);
	cout << ans << endl;
	
	return 0;
}
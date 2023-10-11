#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int &x: a)
		cin >> x;
	int suf[n+1];
	suf[n] = 0;
	for(int i = n-1; i >= 0; i--)
		suf[i] = suf[i+1] + a[i];
	int ans, mn = 1e9+7;
	for(int i = 0; i+k <= n; i++)
		if(mn > suf[i]-suf[i+k])
			mn = suf[i]-suf[i+k], ans = i+1;
	cout << ans << endl;
	
	return 0;
}
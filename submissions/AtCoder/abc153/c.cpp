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
	sort(a, a+n);
	ll ans = 0;
	for(int i=0; i<n-k; i++)
		ans += a[i];
	cout << ans << endl;
	
	return 0;
}
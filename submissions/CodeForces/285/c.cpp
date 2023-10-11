#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n;
	cin >> n;
	int a[n];
	for(int &x: a)
		cin >> x;
	sort(a, a+n);
	unsigned ll ans = 0;
	for(int i = 0; i < n; i++)
		ans += abs(i+1-a[i]);
	cout << ans << endl;
	
	return 0;
}
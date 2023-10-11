#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n, m, d;
	cin >> n >> m >> d;
	int a[n*m];
	for(int i=0; i<n*m; i++)
		cin >> a[i];
	int same = a[0]%d;
	ll ans = 0;
	sort(a, a+n*m);
	for(int i=0; i<n*m; i++)
		if(a[i]%d != same){
			ans = -1;
			break;
		}
	if(ans != -1){
		for(int i=0; i<n*m; i++)
			ans += abs(a[i]-a[n*m/2]);
		ans /= d;
	}
	cout << ans << endl;
	
	return 0;
}
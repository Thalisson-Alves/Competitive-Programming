#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll x, y, n;
	cin >> x >> y >> n;
	const int mod = 1e9+7;
	int rest = n%6;
	int ans;
	switch(rest){
		case 0:
			ans = ((-y+x)%mod+mod)%mod;
			break;
		case 1:
			ans = (x+mod)%mod;
			break;
		case 2:
			ans = (y+mod)%mod;
			break;
		case 3:
			ans = ((y-x)%mod+mod)%mod;
			break;
		case 4:
			ans = (-x+mod)%mod;
			break;
		default:
			ans = (-y+mod)%mod;
			break;
	}
	
	cout << ans << endl;
	
	return 0;
}
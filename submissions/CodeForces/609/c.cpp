#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n;
	cin >> n;
	ll a[n];
	ll media = 0;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		media += a[i];
	}
	ll w = (ll)media % n;
	media = media/n;
	ll ans = 0;
	sort(a, a+n, greater<ll>());
	for(ll x: a)
		if(w > 0) ans += labs((media+1) - (ll)x), --w;
		else ans += labs(media-x);
	cout << ans/2ll << endl;
	
	return 0;
}
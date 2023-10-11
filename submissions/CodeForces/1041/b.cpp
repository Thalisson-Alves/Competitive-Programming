#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b){return (b? gcd(b, a%b): a);};

void solve(){
	ll a, b, x, y;
	cin >> a >> b >> x >> y;
	ll k = gcd(x, y);
	cout << min(a/(x/k), b/(y/k)) << endl;
}

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// int t;
	// cin >> t;
	// while(t--)
		solve();

	return 0;
}

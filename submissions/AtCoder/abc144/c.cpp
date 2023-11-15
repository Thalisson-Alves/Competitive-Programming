#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	ll n;
	cin >> n;
	ll ans = 1e12+1;

	if(!n)
		ans = 1;
	else
		for(ll i = 1; i*i <= n; i++)
			if(n%i==0)
				ans = min(ans, n/i+i-2);
	cout << ans << endl;

    return 0;
}

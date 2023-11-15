#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, a, b;
	cin >> n >> a >> b;
	ll ans = n/(a+b)*a;
	cout << ans + min(n%(a+b), a) << endl;
	
	return 0;
}
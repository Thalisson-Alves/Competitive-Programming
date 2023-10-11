#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	ll n, m;
	cin >> n >> m;
	
	int ans = 0;
	for(ll i = 0; i <= max(n, m); i++){
		if(i*i <= n && (n-(i*i))*(n-(i*i)) == m-i){
			ans++;
		}
	}
	cout << ans << endl;

    return 0;
}
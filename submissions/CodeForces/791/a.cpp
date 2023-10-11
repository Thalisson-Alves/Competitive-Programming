#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	ll ans = 0;
	while(a <= b){
		a *= 3;
		b*=2;
		ans++;
	}
	cout << ans << endl;
	
	return 0;
}
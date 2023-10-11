#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m , a;
	cin >> n >> m >> a;
	
	ll ans = (((ll)n/a)+bool(n%a)) * (((ll)m/a)+bool(m%a));
	if(ans <= 0)
		cout << 1 << endl;
	else
		cout << ans << endl;

    return 0;
}
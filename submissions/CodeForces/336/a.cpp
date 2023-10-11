#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll x, y;
	cin >> x >> y;
	if(x > 0 && y > 0)
		cout << 0 << ' ' << x+y << ' ' << x+y << ' ' << 0 << endl;
	else if(x > 0 && y < 0)
		cout << 0 << ' ' << y-x << ' ' << x-y << ' ' << 0 << endl;
	else if(x < 0 && y > 0)
		cout << x-y << ' ' << 0 << ' ' << 0 << ' ' << y-x << endl;
	else
		cout << x+y << ' ' << 0 << ' ' << 0 << ' ' << x+y << endl;

	return 0;
}
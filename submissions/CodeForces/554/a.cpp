#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	ll ans = s.length();
	ans = 25*ans + 26;
	cout << ans << endl;
	
	return 0;
}
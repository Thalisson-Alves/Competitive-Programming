#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cerr << #x << " = " << x << endl


int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	ll n, k;
	cin >> n >> k;
	cout << min(n, min(k-n%k, n%k)) << endl;
	
	return 0;
}
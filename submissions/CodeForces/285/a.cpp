#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for(int i=1, ks = k; i<=n; i++)
		if(k)
			--k, cout << n-i+1 << (i == n? '\n': ' ');
		else
			cout << i-ks << (i == n? '\n': ' ');

	return 0;
}
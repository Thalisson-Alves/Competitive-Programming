#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int same = k/n;
	int diff = k - (n-1)*same;
	for(int i=0, x=n-1; i<n; i++, x--)
		for(int j=0; j<n; j++)
			cout << (j==x? diff: same) << (j==n-1? '\n': ' ');

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	char a[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
		
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << (a[i][j] == '.'? ((i+j)%2? 'W': 'B'): '-');
		cout << '\n';
	}
	
	return 0;
}

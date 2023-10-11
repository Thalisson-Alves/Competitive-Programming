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
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> a[i][j];
	int ans = 0;
	for(int i=0; i<n; i++){
		bool s = false;
		for(int j=0; j<m; j++)
			if(a[i][j] == 'S'){
				s = true;
				break;
			}
		if(!s)
			for(int j=0; j<m; j++)
				if(a[i][j] == '.')
					ans++, a[i][j] = '-';
	}
	
	for(int i=0; i<m; i++){
		bool s = false;
		for(int j=0; j<n; j++)
			if(a[j][i] == 'S'){
				s = true;
				break;
			}
		if(!s)
			for(int j=0; j<n; j++)
				if(a[j][i] == '.')
					ans++, a[j][i] = '-';
	}
	cout << ans << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1, j = 1; i <= n; i++){
		for(j = 1 ; i*i + j*j <= n*n; j++){
			int c = sqrt(i*i+j*j);
			if(c*c == i*i+j*j)
				ans++;
		}
	}
	
	cout << ans/2 << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n, p[3];
	cin >> n;
	for(int &x: p)
		cin >> x;
	
	int ans = 0;
	for(int i = 0; n >= 0; n -= p[2], i++){
		for(int j = 0, temp = n; temp >= 0; temp -= p[1], j++){
			if(temp % p[0] == 0 || temp == 0)
				ans = max(ans, i+j+temp/p[0]);
		}
	}
	cout << ans << endl;
	
	return 0;
}
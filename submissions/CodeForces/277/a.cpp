#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cerr << #x << " = " << x << endl

int f[101], b[101];

int find(int x){ return x == f[x]? x: find(f[x]); }

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n, m;
	cin >> n >> m;
	bool flag = false;
	for(int i=1; i<=n; i++){
		f[i] = i;
		int t;
		cin >> t;
		while(t--){
			flag = true;
			int x;
			cin >> x;
			(b[x] == 0? b[x] = i: f[find(b[x])] = i);
		}
	}
	
	int ans = 0;
	for(int i=1; i<=n; i++)
		ans += (f[i] == i? 1: 0);
	cout << ans-flag << endl;
	
	return 0;
}
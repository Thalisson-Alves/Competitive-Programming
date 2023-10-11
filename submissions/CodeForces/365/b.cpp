#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cerr << #x << " = " << x << endl

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n;
	cin >> n;
	int a[n];
	for(int &x: a)
		cin >> x;
	int ans = 2;
	for(int i=2, len=2; i<n; i++){
		if(a[i] == a[i-1]+a[i-2])
			len++;
		else
			len = 2;
		ans = max(ans, len);
	}
	cout << min(ans, n) << endl;
	
	return 0;
}
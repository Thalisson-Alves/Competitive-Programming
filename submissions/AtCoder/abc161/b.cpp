#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cerr << #x << " = " << x << endl


int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n, m;
	cin >> n >> m;
	int a[n], sum = 0;
	for(int &x: a)
		cin >> x, sum+=x;
	sort(a, a+n);
	bool ans = true;
	for(int i=n-1; i>=n-m; i--)
		if(a[i] < ceil(sum/(4.0*m))){
			ans = false;
			break;
		}

	cout << (ans? "Yes\n": "No\n");
	
	return 0;
}
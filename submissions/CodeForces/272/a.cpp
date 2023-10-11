#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 0, a; i< n; i++)
		cin >> a, sum+=a;
	int ans = 0;
	for(int i = 1; i <= 5; i++)
		if((sum + i)%(n+1) != 1)
			ans++;
	cout << ans << endl;

	return 0;
}
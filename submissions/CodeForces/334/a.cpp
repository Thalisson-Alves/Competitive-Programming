#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> ans(n, vector<int>(n));
	int count[n];
	memset(count, 0, sizeof count);
	for(int i=1, p=0; i <= n*n; i+=2, p=(p+1)%n)
		ans[p][count[p]++] = i, ans[p][count[p]++] = n*n-i+1;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cout << ans[i][j] << (j+1==n? '\n': ' ');

	return 0;
}
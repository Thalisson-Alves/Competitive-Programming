#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int a[n];
	int sum = 0, even = 0, odd = 0;
	for(int i=0, x; i<n; i++)
		cin >> x, (x%2? odd+=1: even+=1), sum+=x;
	cout << (sum%2? odd: even) << endl;
	
	return 0;
}
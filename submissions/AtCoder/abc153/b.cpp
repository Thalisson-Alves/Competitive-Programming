#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int h, n;
	cin >> h >> n;
	ll sum = 0;
	for(int i=0, a; i<n; i++)
		cin >> a, sum += a;
	cout << (sum >= h? "Yes\n": "No\n");
	
	return 0;
}
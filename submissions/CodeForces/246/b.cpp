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
	for(int i=0, x; i<n; i++)
		cin >> x, sum += x;
	cout << (sum%n? n-1: n) << endl;
	
	return 0;
}
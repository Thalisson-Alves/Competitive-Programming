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
	sort(a, a+n);
	swap(a[0], a[n-1]);
	for(int i=0; i<n; i++)
		cout << a[i] << (i+1 == n? '\n': ' ');
	
	return 0;
}
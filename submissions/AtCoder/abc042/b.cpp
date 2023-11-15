#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cerr << #x << " = " << x << endl

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n, l;
	cin >> n >> l;
	string s[n];
	for(int i=0; i<n; i++)
		cin >> s[i];
	sort(s, s+n);
	for(int i=0; i<n; i++)
		cout << s[i];
	cout << '\n';
	
	return 0;
}
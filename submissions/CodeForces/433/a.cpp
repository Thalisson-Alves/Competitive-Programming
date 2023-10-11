#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n;
	cin >> n;
	int th = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		th += a==100;
	}
	if((th == 0 && n % 2) || th % 2)
		cout << "NO\n";
	else
		cout << "YES\n";
	
	return 0;
}
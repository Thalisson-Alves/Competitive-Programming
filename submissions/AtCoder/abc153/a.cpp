#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int h, x;
	cin >> h >> x;
	cout << ceil((double)h/x) << endl;
	
	return 0;
}
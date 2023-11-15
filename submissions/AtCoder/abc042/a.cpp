#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cerr << #x << " = " << x << endl

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int five = 0;
	int seven = 0;
	for(int i=0, x; i<3; i++)
		cin >> x, (x == 5? five++: x == 7? seven++: 0);
	if(five == 2 && seven == 1)
		cout << "YES\n";
	else
		cout << "NO\n";
	
	return 0;
}
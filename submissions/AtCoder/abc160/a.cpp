#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cerr << #x << " = " << x << endl

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	string s;
	cin >> s;
	if(s[2] == s[3] && s[4] == s[5])
		cout << "Yes\n";
	else
		cout << "No\n";
	
	return 0;
}
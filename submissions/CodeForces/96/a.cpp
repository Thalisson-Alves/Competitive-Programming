#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	string s;
	cin >> s;
	int z = s.find("0000000"), o = s.find("1111111");
	if(z < s.length() || o < s.length())
		cout << "YES\n";
	else 
		cout << "NO\n";
	
    return 0;
}

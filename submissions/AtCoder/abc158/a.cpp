#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	bool A = false, B = false;
	string s;
	cin >> s;
	for(char c: s)
		if(c == 'A')
			A = true;
		else
			B = true;
		
	cout << (A&&B? "Yes\n": "No\n") << endl;
	
	return 0;
}
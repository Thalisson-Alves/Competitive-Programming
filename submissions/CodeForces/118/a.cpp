#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	string s;
	cin >> s;
	for(char &c: s){
		char ch = tolower(c);
		if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
			continue;
		cout << '.' << ch;
	}
	cout << endl;
	
    return 0;
}

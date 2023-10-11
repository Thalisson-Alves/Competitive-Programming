#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
	cin >> s; cin.ignore();
	string t;
	cin >> t;
	
	if(s.length() != t.length())
		cout << "NO" << endl;
	else{
		for(int i = 0; i < s.length(); i++)
			if(s[i] != t[s.length()-1-i]){
				cout << "NO\n";
				return 0;
			}
		cout << "YES\n";
	}

    return 0;
}
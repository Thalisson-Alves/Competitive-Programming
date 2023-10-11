#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	string head;
	string text;
	getline(cin, head);
	getline(cin, text);
	map<char, int> mp;
	for(char c: head)
		mp[c]++;
	bool ans = true;
	for(char c: text)
		if(c != ' ' && mp[c]-- <= 0)
			ans = false;
	if(ans)
		cout << "YES\n";
	else
		cout << "NO\n";
	
	return 0;
}
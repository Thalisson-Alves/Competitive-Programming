#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	map<string, int> mp;
	string s1, s2;
	cin >> s1 >> s2;
	cin >> mp[s1] >> mp[s2];
	string t;
	cin >> t;
	mp[t]--;
	cout << mp[s1] << ' ' << mp[s2] << endl;
	
	return 0;
}
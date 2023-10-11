#include <bits/stdc++.h>
using namespace std;
#define ll long long

string reverse(string t, int l){
	string tmp;
	for(int i = l-1; i>=0; i--)
		tmp += t[i];
	return tmp;
}

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n;
	string s;
	cin >> n >> s;
	string ans;
	for(int i = 1; i <= n; i++)
		if(n%i==0){
			ans = reverse(s.substr(0, i), i);
			s = ans + s.substr(i);
		}
	cout << ans << endl;

	return 0;
}
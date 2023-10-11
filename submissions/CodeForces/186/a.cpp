#include <bits/stdc++.h>
using namespace std;
#define ll long long

int mpa[27], mpb[27];

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	string a, b;
	cin >> a >> b;
	for(char c: a)
		mpa[c-'a']++;
	for(char c: b)
		mpb[c-'a']++;
	
	bool ans = true;
	for(int i = 0; i < 27; i++)
		if(mpa[i] != mpb[i])
			ans = false;
	if(!ans){
		cout << "NO\n";
		return 0;
	}
	int dif = 0;
	for(int i = 0; i < a.size(); i++)
		dif += a[i] != b[i];
	if(dif == 2)
		cout << "YES\n";
	else
		cout << "NO\n";
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n;
	cin >> n;
	string s;
	cin >> s;
	sort(s.begin(), s.begin()+n);
	sort(s.begin()+n, s.end());
	bool lucky = false;
	bool gt = s[0] > s[n];
	for(int i = 0; i < n; i++)
		if(s[i] == s[i+n] || gt != s[i] > s[i+n])
			lucky = true;
	
	if(lucky)
		cout << "NO\n";
	else
		cout << "YES\n";
	
	return 0;
}
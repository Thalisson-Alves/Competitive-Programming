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
	int n = s.length();
	function<bool(string)> is_palindrome = [](const string &s) -> bool {
		int n = s.length();
		for(int i=0; i<n/2; i++)
			if(s[i] != s[n-i-1])
				return false;
		return true;
	};
	cout << (is_palindrome(s) && is_palindrome(s.substr(0, (n-1)/2)) && is_palindrome(s.substr((n+2)/2))? "Yes\n": "No\n");
	
	return 0;
}
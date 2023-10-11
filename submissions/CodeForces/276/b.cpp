#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.length();
	unordered_map<char, int> mp;
	for(char &c: s)
		mp[c]++;
	
	bool palindrome = true;
	int solo = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		if(it->second == 1)
			solo++;
		if(solo > 1 || it->second%2){
			palindrome = false;
			break;
		}
	}
	if(palindrome || n%2)
		cout << "First\n";
	else
		cout << "Second\n";

	return 0;
}
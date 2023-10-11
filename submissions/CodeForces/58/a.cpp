#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, ans;
	cin >> s;
	int t = 0;
	char letter[] = {'h', 'e', 'l', 'l', 'o'};
	for(char &c: s)
		if(c == letter[t])
			if(t < 5){
				ans += letter[t++];
			}else break;
	
	if(!ans.empty() && ans == "hello")
		cout << "YES\n";
	else
		cout << "NO\n";
	
	return 0;
}

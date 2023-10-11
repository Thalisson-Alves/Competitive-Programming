#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	string s, ans = " ";
	getline(cin, s);
	for(int i=2; i < s.size(); i++){
		if(s[i] == 'B' && s[i-1] == 'U' && s[i-2] == 'W'){
			i+=2;
			if(ans.back() != ' ')
				ans += ' ';
		}
		else
			ans += s[i-2];
	}
	auto t = s.length();
	if(t < 3 || (t == 3 && s != "WUB"))
		ans += s;
	else if(t > 3){
		if(s.substr(t-3) != "WUB"){
			if(s.substr(t-4, 3) != "WUB")
				ans += s.substr(t-2);
			else
				ans += s.substr(t-1);
		}
	}
	ans = ans.substr(1);
	if(ans.empty())
		ans = "";
	
	cout << ans << endl;
	
    return 0;
}

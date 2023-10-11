#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int k;
	cin >> k; cin.ignore();
	string s;
	cin >> s;
	if(s.size()%k)
		cout << -1 << endl;
	else{
		unordered_map<char, int> mp;
		for(char &c: s)
			mp[c]++;
		
		string ans;
		for(auto it = mp.begin(); it != mp.end(); it++){
			if(it->second % k){
				cout << -1 << endl;
				return 0;
			}
			for(int i = 0; i < it->second/k; i++)
				ans += it->first;
		}
		for(int i = 0; i < k; i++)
			cout << ans;
		cout << endl;
	}
	
    return 0;
}

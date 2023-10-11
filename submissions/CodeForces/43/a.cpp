#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
	cin >> n; cin.ignore();
	unordered_map<string, int> mp;
	while(n--){
		string s;
		cin >> s; cin.ignore();
		mp[s]++;
	}
	pair<string, int> ans;
	for(auto it = mp.begin(); it != mp.end(); it++)
		if(it->second > ans.second){
			ans.first = it->first;
			ans.second = it->second;
		}
	
	cout << ans.first << endl;

    return 0;
}
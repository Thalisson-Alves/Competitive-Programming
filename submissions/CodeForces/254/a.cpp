#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
 
	int n;
	cin >> n;
	map<int, vector<int>> mp;
	map<int, int> count;
	for(int i = 1; i <= 2*n; i++){
		int x;
		cin >> x;
		mp[x].push_back(i);
		count[x]++;
	}
	for(auto it = count.begin(); it != count.end(); it++){
		if(it->second % 2){
			cout << -1 << endl;
			return 0;
		}
	}
	vector<pair<int, int>> ans;
	for(auto it = mp.begin(); it != mp.end(); it++){
		for(int i = 0, j=0; i < it->second.size()/2; i++)
			ans.push_back({it->second[j++], it->second[j++]});
	}
	if(!ans.empty())
		for(auto it = ans.begin(); it != ans.end(); it++)
			cout << it->first << ' ' << it->second << endl;
	else
		cout << -1 << endl;
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int a[n];
	map<int, vector<int>> mp;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mp[a[i]].push_back(i);
	}
	set<pair<int, int>> ans;
	for(auto it = mp.begin(); it != mp.end(); it++){
		if(it->second.size() == 1)
			ans.insert(make_pair(it->first, 0));
		else{
			int dif = it->second[1] - it->second[0];
			for(int i = 2; i < it->second.size(); i++){
				if(it->second[i] - it->second[i-1] != dif){
					dif = -1;
				}
			}
			if(dif != -1)
				ans.insert(make_pair(it->first, dif));
		}
	}
	
	cout << ans.size() << endl;
	for(pair<int, int> pp: ans)
		cout << pp.first << " " << pp.second << endl;
	
	return 0;
}
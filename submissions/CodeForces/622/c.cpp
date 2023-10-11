#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

	int n, m;
	scanf("%d %d", &n, &m);
	int prev = 0;
	map<int, vector<pair<int, int>>> mp;
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		auto it = mp.find(a[i]);
		if(it == mp.end()){
			mp[a[i]].push_back(make_pair(i+1, i+1));
		}
		else if (prev == a[i]){
			(it->second).back() = make_pair(min(i+1, (it->second).back().first), i+1);
		}
		else{
			(it->second).push_back(make_pair(i+1, i+1));
		}
		prev = a[i];
	}
	for(int i = 0; i < m; i++){
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);
		if(a[r-1] != x)
			printf("%d\n", r);
		else if (a[l-1] != x)
			printf("%d\n", l);
		else{
			int ans = -1;
			for(pair<int, int> pp : mp[x]){
				if(l >= pp.first && r <= pp.second){
					ans = -1;
					break;
				}
				else if(l >= pp.first && l <= pp.second){
					ans = pp.second+1;
					break;
				}
				else if(r >= pp.first && r <= pp.second){
					ans = pp.first-1;
					break;
				}
			}
			printf("%d\n", ans);
		}
	}
	
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, bool>> a(n);
	for(int i = 0; i<n;i++)
		cin >> a[i].first;
	
	for(int i = 0; i < m; i++){
		int b;
		cin >> b;
		a[b-1].second = true;
	}
	
	sort(a.begin(), a.end(), [](pair<int, bool> a, pair<int, bool> b){
		if(a.second == b.second) return a.first > b.first;
		return !a.second;
	});
	
	ll ans = 0;
	for(auto it = a.begin(); it != a.end(); it++)
		ans += (it->second? (ans > it->first? ans: it->first):it->first);
	
	cout << ans << endl;
	
	return 0;
}
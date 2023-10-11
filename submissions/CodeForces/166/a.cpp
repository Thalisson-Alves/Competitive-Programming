#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n, k;
	cin >> n >> k;
	map<pair<int, int>, int> mp;
	pair<int, int> a[n];
	for(int i = 0, p, t; i < n; i++)
		cin >> p >> t, mp[{p, t}]++, a[i] = {p, t};
	sort(a, a+n, [](pair<int, int> a, pair<int, int> b){
		if(a.first != b.first) return a.first > b.first;
		return a.second < b.second;
	});
	cout << mp[{a[k-1].first, a[k-1].second}] << endl;

	return 0;
}
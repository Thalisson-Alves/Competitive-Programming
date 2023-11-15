#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cerr << #x << " = " << x << endl

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n;
	cin >> n;
	int a[n];
	map<int, int> mp;
	for(int i=0; i<n; i++)
		cin >> a[i], mp[a[i]]++;
	function<ll(int)> sum = [](const int &n) -> ll {
		return (n-1ll)*n/2ll;
	};
	ll mx = 0ll;
	for(auto it=mp.begin(); it!=mp.end(); it++)
		mx += sum(it->second);
	for(int i=0; i<n; i++)
		cout << mx-mp[a[i]]+1 << endl;
	
	return 0;
}
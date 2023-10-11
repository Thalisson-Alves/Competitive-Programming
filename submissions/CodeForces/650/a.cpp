#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll sum(ll x){ 
	return ((1.f+x)*x/2.0);
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<ll, ll>> p(n);
	unordered_map<ll, ll> xs, ys;
	map<pair<ll, ll>, ll> mp;
	for(int i = 0; i < n; i++){
		cin >> p[i].first >> p[i].second;
		mp[p[i]]++;
		xs[p[i].first]++;
		ys[p[i].second]++;
	}
	
	ll ans = 0;
	for(auto it = xs.begin(); it != xs.end(); it++)
		ans += sum(it->second-1);
	
	for(auto it = ys.begin(); it != ys.end(); it++)
		ans += sum(it->second-1);
	
	for(auto it = mp.begin(); it != mp.end(); it++)
		ans -= sum(it->second-1);
	
	cout << ans << endl;

    return 0;
}
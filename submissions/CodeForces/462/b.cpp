#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;cin.ignore();
	string s;
	cin >> s;
	unordered_map<char, int> mp;
	for(char &c: s)
		mp[c]++;
	priority_queue<int> a;
	for(auto it = mp.begin(); it != mp.end(); it++)
		a.push(it->second);
	ll ans = 0;
	while(!a.empty()){
		int tp = a.top();
		a.pop();
		ans += (m >= tp? (ll)tp*tp: (ll)m*min(m, tp));
		m -= tp;
		if(m <= 0)
			break;
	}
	cout << ans << endl;
	
	return 0;
}
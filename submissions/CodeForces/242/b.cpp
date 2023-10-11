#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int mn = 1e9+1, mx = -1;
	map<pair<int, int>, int> mp;
	for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        mp[{l, r}] = i+1;
        mn = min(mn, l);
        mx = max(mx, r);
	}
	if(mp.find({mn, mx}) != mp.end())
        cout << mp[{mn, mx}] << endl;
    else
        cout << -1 << endl;

	return 0;
}

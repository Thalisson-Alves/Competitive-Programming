#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int g[5][5];
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cin >> g[i][j];
		}
	}
	map<pair<int, int>, ll> mp;
	for(int i = 0; i < 5; i++){
		for(int j = i+1; j < 5; j++){
			mp[{i+1, j+1}] = g[i][j] + g[j][i];
		}
	}
	
	ll ans = 0;
	
	function<bool(int, int, int, int, int)> dif = [](int a, int b, int c, int d, int e) -> bool {
		return (a!=b && a!=c && a!=d && a!=e && b!=c && b!=d && b!=e && c!=d && c!=e && d!=e);
	};
	
	for(int a = 1; a <= 5; a++)
		for(int b = 1; b <= 5; b++)
			for(int c = 1; c <= 5; c++)
				for(int d = 1; d <= 5; d++)
					for(int e = 1; e <= 5; e++)
						if(dif(a, b, c, d, e))
							ans = max((mp[{min(a, b), max(a, b)}] + mp[{min(b, c), max(b, c)}] + 2*mp[{min(c, d), max(c, d)}] + 2*mp[{min(d, e), max(d, e)}]), ans);
	
	cout << ans << '\n';

	return 0;
}
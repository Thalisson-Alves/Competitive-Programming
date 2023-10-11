#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
	int t, sx, sy, ex, ey;
	cin >> t >> sx >> sy >> ex >> ey;
	int v = ey-sy;
	int h = ex - sx;
	
	int ans = -1;
	for(int i = 0; i < t; i++){
		char dir;
		cin >> dir;
		v += (v > 0 && dir == 'N'? -1: (v < 0 && dir == 'S'? 1: 0));
		h += (h > 0 && dir == 'E'? -1: (h < 0 && dir == 'W'? 1: 0));
		if(h == 0 && v == 0 && ans == -1)
			ans = i+1;
	}
	cout << ans << endl;
}

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// int t;
	// cin >> t;
	// while(t--)
		solve();

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> hole(n+1);
    for(int i = 0; i < m; i++){
        int h;
        cin >> h;
        hole[h] = true;
    }
    int ans = 1;
    for(int i = 0; i < k; i++){
        int p1, p2;
        cin >> p1 >> p2;
        ans = (!hole[ans]? (p1 == ans? p2: (p2 == ans? p1: ans)): ans);
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

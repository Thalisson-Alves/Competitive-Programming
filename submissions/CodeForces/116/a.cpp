#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	int ans = 0;
	int current = 0;
	for(int i = 0; i < n; i++){
        int o, in;
        cin >> o >> in;
        current += in-o;
        ans = max(ans, current);
	}
	cout << ans << endl;
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int t;
    //cin >> t;
    //while(t--)
        solve();

    return 0;
}

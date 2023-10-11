#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int ans = -1e9;
	while(n--){
		int f, t;
		cin >> f >> t;
		ans = max(ans, (t > k? f-(t-k): f));
	}
	cout << ans << endl;

	return 0;
}
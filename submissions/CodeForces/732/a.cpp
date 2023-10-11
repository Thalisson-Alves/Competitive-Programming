#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k, r;
	cin >> k >> r;
	int ans;
	for(ans = 1; ans < 10; ans++){
        if((k*ans)%10 == r || k*ans % 10 == 0)
            break;
	}
	cout << ans << endl;

	return 0;
}

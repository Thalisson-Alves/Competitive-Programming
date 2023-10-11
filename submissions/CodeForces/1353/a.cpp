#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	int n, m;
	cin >> n >> m;
	if(n == 1){
		cout << 0 << endl;
		return;
	}
	if(n == 2){
		cout << m << endl;
		return;
	}
	cout << 2ll*m << endl;
	return;
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();

    return 0;
}
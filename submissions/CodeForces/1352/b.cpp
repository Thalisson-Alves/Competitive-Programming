#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;
	if(n%2 && !(k%2)){
		cout << "NO\n";
		return;
	}
	if(!(n%2) && k%2){
		if(n < 2*k){
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
		for(int i = 1; i < k; i++)
			cout << "2 ";
		cout << n-(2*(k-1)) << endl;
	} else {
		if(n < k){
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
		for(int i = 1; i < k; ++i)
			cout << "1 ";
		cout << n-(k-1) << endl;
	}
}

int main(int qtd, char* nome[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(int qtd, char* nome[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	if(n-m >= 2 || m > 2*n+2)
        cout << -1;
    else{
        if(m >= n){
            while(n){
                cout << "1";
                m--;
                if(m > n--)
                    cout << '1', m--;
                cout << '0';
            }
            while(m--) cout << '1';
        }else{
            cout << '0';
            n--;
            while(n--)
                cout << "10";
        }
    }
    cout << '\n';

	return 0;
}

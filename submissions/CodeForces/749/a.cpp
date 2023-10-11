#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	if(n%2){
        cout << n/2 << endl;
        for(int i = 0; i < n/2-1; i++)
            cout << "2 ";
        cout << "3\n";
	}else{
	    cout << n/2 << endl;
        for(int i = 0; i < n/2; i++){
            cout << "2 ";
        }
        cout << endl;
	}
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


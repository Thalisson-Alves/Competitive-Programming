#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	int p[n][2];
	int sumU = 0, sumD = 0, inv = 0, sU = 0, sD = 0;
	for(int i = 0; i < n; i++){
        cin >> p[i][0] >> p[i][1];
        if(p[i][1]%2)
            sumD++;
        if(p[i][0] % 2)
            sumU++;
        if((p[i][0]%2) ^ (p[i][1]%2))
            inv ++;
        sU += p[i][0];
        sD += p[i][1];
	}
	if((sumD + sumU)%2){
        cout << -1 << endl;
        return;
	}
	if(sU%2==0 && sD%2==0){
        cout << 0 << endl;
        return;
	}
    if((sU%2 ^ sD%2) && inv > 1){
        cout << 2 << endl;
        return;
    }
    if((sU%2) && (sD%2) && inv){
        cout << 1 << endl;
        return;
    }
    cout << -1 << endl;
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

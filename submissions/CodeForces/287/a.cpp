#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    char p[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> p[i][j];
        }
    }
    string ans = "NO";
    for(int i = 1; i < 4; i++){
        for(int j = 1; j < 4; j++){
            int val = 0;
            if(p[i-1][j-1] == '.')
                val++;
            if(p[i][j-1] == '.')
                val++;
            if(p[i-1][j] == '.')
                val++;
            if(p[i][j] == '.')
                val++;
            if(val == 3 || val == 4 || val == 1 || val == 0){
                ans = "YES";
                break;
            }
        }
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

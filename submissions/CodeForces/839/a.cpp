#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k; cin.ignore();
	int ans = -1;
	int given = 0;
	int remaing = 0;
	for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        remaing += x;
        if(remaing < 8){
            given += remaing;
            remaing = 0;
        }
        else{
            given += 8;
            remaing -= 8;
        }
        if(given >= k){
            ans = i+1;
            break;
        }
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
